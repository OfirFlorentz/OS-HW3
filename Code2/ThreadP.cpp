#include "ThreadP.hpp"
#include "Thread.hpp"
#include "PCQueue.hpp"
#include "Job.hpp"

ThreadP::ThreadP(uint thread_id, vector<vector<int>> *curr_board, vector<vector<int>> *next_board, PCQueue<Job> *pcq,
                 vector<double> *hist, pthread_mutex_t *mutex, uint *s_finish_phase) :
                 Thread(thread_id), curr_board(curr_board), next_board(next_board), s_pcq(pcq),
                 s_tile_hist(hist), s_mutex(mutex), s_finish_phase(s_finish_phase) {}


void ThreadP::thread_workload() {
    while (1) {
        Job job = s_pcq->pop(); // also uses as cond_wait

        auto start = std::chrono::system_clock::now();
        int start_line = job.get_start_line();
        int num_of_lines = job.get_num_of_lines();

        if (job.get_which_phase()) { // phase1
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
                            (*next_board)[i][j] = dominant_species;
                        }
                    } else if ((*curr_board)[i][j] != 0 && num_of_neighbours != 2 && num_of_neighbours != 3) {
                        (*next_board)[i][j] = 0;
                    } else {
                        (*next_board)[i][j] = (*curr_board)[i][j];
                    }
                }
            }
        }
        else { // phase2
            for (int i = start_line; i < start_line + num_of_lines; ++i) {
                int bottom = 0 > i - 1 ? 0 : i - 1;
                int top = i + 1 < (int) next_board->size() ? i + 1 : (int)next_board->size() - 1;

                for (int j = 0; j < (int) (*next_board)[i].size(); ++j) {
                    if ((*next_board)[i][j] == 0) {
                        (*curr_board)[i][j] = 0;
                        continue;
                    }

                    int left = 0 > j - 1 ? 0 : j - 1;
                    int right = (int) (*next_board)[i].size() - 1 < j + 1 ? (int) (*next_board)[i].size() - 1 : j + 1;

                    double num_of_neighbours = 0;
                    double sum_vals = 0;
                    for (int k = bottom; k <= top; ++k) { // count num of alive neighbours
                        for (int l = left; l <= right; ++l) {
                            if ((*next_board)[k][l] != 0) {
                                num_of_neighbours++;
                                sum_vals += (*next_board)[k][l];
                            }
                        }
                    }
                    (*curr_board)[i][j] = round(sum_vals / num_of_neighbours); // num_of_neighbours>0 due phase1
                }
            }
        }

        pthread_mutex_lock(s_mutex);
        (*s_finish_phase)--;
        auto end = std::chrono::system_clock::now();
        s_tile_hist->push_back((double) std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
        pthread_mutex_unlock(s_mutex);

        if(job.get_is_last_call()) { // if last time, we let him to finish inorder to use join right after
            return;
        }
    }
}
