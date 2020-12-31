//
// Created by student on 12/28/20.
//

#ifndef WET3_FILES_THREADP_H
#define WET3_FILES_THREADP_H

#include "Thread.hpp"

class ThreadP: public Thread{
    void thread_workload() override;
public:
    ThreadP(uint thread_id);
    ~ThreadP() = default;
};

#endif //WET3_FILES_THREADP_H



