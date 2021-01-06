#include "ThreadP.hpp"
#include "Thread.hpp"
#include "PCQueue.hpp"
#include "Job.hpp"

ThreadP::ThreadP(uint thread_id, vector<vector<int>> *curr_board, vector<vector<int>> *mid_board,
                 vector<vector<int>> *next_board, PCQueue<Job> *pcq, vector<float> *hist, pthread_mutex_t *mutex,
                 pthread_cond_t *cond, uint *s_phase1, uint *s_phase2) :
                 Thread(thread_id), curr_board(curr_board), mid_board(mid_board), next_board(next_board), s_pcq(pcq),
                 s_tile_hist(hist), s_mutex(mutex), s_cond(cond), s_stopper_phase1(s_phase1), s_stopper_phase2(s_phase2){}


void ThreadP::thread_workload() {
    while (1) {
        Job job = s_pcq->pop(); // also uses as cond_wait

        auto start = std::chrono::system_clock::now();
        int start_line = job.get_start_line();
        int num_of_lines = job.get_num_of_lines();

        // start phase 1
        for (int i = start_line; i < start_line + num_of_lines; ++i) {
            int bottom = 0 > i - 1 ? 0 : i - 1;
            int top = i + 1 < (int) curr_board->size() ? i + 1 : (int) curr_board->size() - 1;

            for (int j = 0; j < (int) (*curr_board)[i].size(); ++j) {
                int left = 0 > j - 1 ? 0 : j - 1;
                int right = (int) (*curr_board)[i].size() - 1 < j + 1 ? (int) (*curr_board)[i].size() - 1 : j + 1;

                int num_of_neighbours = 0;
                int colors_hist[8] = {0, 0, 0, 0, 0, 0, 0, 0};
                for (int k = bottom; k <= top; ++k) { // count num of alive neighbours
                    for (int l = left; l <= right; ++l) {
                        if (k == i && l == j) {
                            continue;
                        } else if ((*curr_board)[k][l] != 0) {
                            if (++num_of_neighbours <= 3) {
                                colors_hist[((*curr_board)[k][l])]++; // mapping dominant species of neighbours
                            }
                        }
                    }
                }

                if ((*curr_board)[i][j] == 0 && num_of_neighbours == 3) {
                    int dominant_species = 0;
                    int max = 0;
                    for (int k = 0; k < 8; ++k) {
                        if (colors_hist[k] * k > max) {
                            max = colors_hist[k] * k;
                            dominant_species = k;
                        }
                        (*mid_board)[i][j] = dominant_species;
                    }
                } else if ((*curr_board)[i][j] != 0 && num_of_neighbours != 2 && num_of_neighbours != 3) {
                    (*mid_board)[i][j] = 0;
                } else {
                    (*mid_board)[i][j] = (*curr_board)[i][j];
                }
            }
        }

        pthread_mutex_lock(s_mutex);
        (*s_stopper_phase1)--;
        while ((*s_stopper_phase1) != 0) {
            pthread_cond_wait(s_cond, s_mutex);
        }
        pthread_mutex_unlock(s_mutex);

        // start phase 2
        for (int i = start_line; i < start_line + num_of_lines; ++i) {
            int bottom = 0 > i - 1 ? 0 : i - 1;
            int top = i + 1 < (int) mid_board->size() ? i + 1 : mid_board->size() - 1;

            for (int j = 0; j < (int) (*mid_board)[i].size(); ++j) {
                if ((*mid_board)[i][j] == 0) {
                    (*next_board)[i][j] = 0;
                    continue;
                }

                int left = 0 > j - 1 ? 0 : j - 1;
                int right = (int) (*mid_board)[i].size() - 1 < j + 1 ? (int) (*mid_board)[i].size() - 1 : j + 1;

                double num_of_neighbours = 0;
                double sum_vals = 0;
                for (int k = bottom; k <= top; ++k) { // count num of alive neighbours
                    for (int l = left; l <= right; ++l) {
                        if ((*mid_board)[k][l] != 0) {
                            num_of_neighbours++;
                            sum_vals += (*mid_board)[k][l];
                        }
                    }
                }
                (*next_board)[i][j] = round(sum_vals / num_of_neighbours); // num_of_neighbours>0 due phase1
            }
        }

        pthread_mutex_lock(s_mutex);
        (*s_stopper_phase2)--;
        auto end = std::chrono::system_clock::now();
        s_tile_hist->push_back((float) std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
        pthread_cond_broadcast(s_cond);  // TODO
        pthread_mutex_unlock(s_mutex);

        if(job.get_is_last_call()) {
            return;
        }
    }
}
