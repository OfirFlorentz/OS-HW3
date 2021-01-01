//
// Created by student on 12/28/20.
//

#ifndef WET3_FILES_THREADP_H
#define WET3_FILES_THREADP_H

#include "Thread.hpp"

class ThreadP: public Thread{
    vector<vector<int>>* curr_board;
    vector<vector<int>>* next_board;
    int start_line;
    int num_of_line;
    vector<float>* tile_hist;
    pthread_mutex_t* mutex;

public:
    ThreadP(uint thread_id, vector<vector<int>>* curr_board, vector<vector<int>>* next_board, int start_line,
            int num_of_line, vector<float>* tile_hist, pthread_mutex_t* mutex);
    ~ThreadP() = default;
    void thread_workload() override;
};

#endif //WET3_FILES_THREADP_H



