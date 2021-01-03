#include "ThreadP.hpp"
#include "Thread.hpp"

ThreadP::ThreadP(uint thread_id, vector<vector<int>>* curr_board, vector<vector<int>>* next_board, int start_line,
                 int num_of_line, vector<float>* tile_hist, pthread_mutex_t* mutex) : Thread(thread_id),
                 curr_board(curr_board), next_board(next_board), start_line(start_line), num_of_line(num_of_line),
                 tile_hist(tile_hist), mutex(mutex), time_temp(0), phase(true) {}

void ThreadP::thread_workload() {
    auto start = std::chrono::system_clock::now();

    if (phase) { // phase 1
        phase = false;

        for (int i = start_line; i < start_line+num_of_line; ++i) {
            int bottom = 0 > i-1 ? 0 : i-1;
            int top = i+1 < (int)curr_board->size() ? i+1 : (int)curr_board->size()-1;

            for (int j = 0; j < (int)(*curr_board)[i].size(); ++j) {
                int left = 0 > j-1 ? 0 : j-1;
                int right = (int)(*curr_board)[i].size()-1 < j+1 ? (int)(*curr_board)[i].size()-1 : j+1;

                int num_of_neighbours = 0;
                int colors_hist [8] = {0,0,0,0,0,0,0,0};
                for (int k = bottom; k <= top; ++k) { // count num of alive neighbours
                    for (int l = left; l <= right; ++l) {
                        if (k == i && l == j) {
                            continue;
                        }
                        else if ((*curr_board)[k][l] != 0) {
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
                        if (colors_hist[k]*k > max) {
                            max = colors_hist[k]*k;
                            dominant_species = k;
                        }
                        (*next_board)[i][j] = dominant_species;
                    }
                }
                else if ((*curr_board)[i][j] != 0 && num_of_neighbours != 2 && num_of_neighbours != 3) {
                    (*next_board)[i][j] = 0;
                }
            }
        }

        auto end = std::chrono::system_clock::now();
        time_temp = (float)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
    else { // phase 2
        phase = true;

        for (int i = start_line; i < start_line+num_of_line; ++i) {
            int bottom = 0 > i-1 ? 0 : i-1;
            int top = i+1 < (int)curr_board->size() ? i+1 : curr_board->size()-1;

            for (int j = 0; j < (int)(*curr_board)[i].size(); ++j) {
                if ((*curr_board)[i][j] == 0) {
                    continue;
                }


                int left = 0 > j-1 ? 0 : j-1;
                int right = (int) (*curr_board)[i].size()-1 < j+1 ? (int) (*curr_board)[i].size()-1 : j+1;

                double num_of_neighbours = 0;
                double sum_vals = 0;
                for (int k = bottom; k <= top; ++k) { // count num of alive neighbours
                    for (int l = left; l <= right; ++l) {
                        if ((*curr_board)[k][l] != 0) {
                            num_of_neighbours++;
                            sum_vals += (*curr_board)[k][l];
                        }
                    }
                }
                (*next_board)[i][j] = round(sum_vals/num_of_neighbours); // num_of_neighbours>0 due phase1
            }
        }

        pthread_mutex_lock(mutex);
        auto end = std::chrono::system_clock::now();
        tile_hist->push_back(time_temp + (float)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
        pthread_mutex_unlock(mutex);
    }
}
