//
// Created by student on 12/28/20.
//

#ifndef WET3_FILES_THREADP_H
#define WET3_FILES_THREADP_H

#include "Thread.hpp"
#include "PCQueue.hpp"
#include "Job.hpp"

class ThreadP: public Thread{
    vector<vector<int>>* curr_board;
    vector<vector<int>>* next_board;

    PCQueue<Job>* s_pcq;
    vector<double>* s_tile_hist;
    pthread_mutex_t* s_mutex;

    uint* s_finish_phase;

public:
    ThreadP(uint thread_id, vector<vector<int>>* curr_board, vector<vector<int>>* next_board, PCQueue<Job>* pcq,
            vector<double>* hist, pthread_mutex_t* mutex, uint* s_finish_phase);
    ~ThreadP() = default;
    void thread_workload() override;
};

#endif //WET3_FILES_THREADP_H



