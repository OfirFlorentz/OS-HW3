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
    vector<vector<int>>* mid_board;
    vector<vector<int>>* next_board;

    PCQueue<Job>* s_pcq;
    vector<double>* s_tile_hist;
    pthread_mutex_t* s_mutex;
    pthread_cond_t* s_cond;

    uint* s_stopper_phase1;
    uint* s_stopper_phase2;

public:
    ThreadP(uint thread_id, vector<vector<int>>* curr_board, vector<vector<int>>* mid_board,
            vector<vector<int>>* next_board, PCQueue<Job>* pcq, vector<double>* hist, pthread_mutex_t* mutex,
            pthread_cond_t* cond, uint* s_phase1, uint* s_phase2);
    ~ThreadP() = default;
    void thread_workload() override;
};

#endif //WET3_FILES_THREADP_H



