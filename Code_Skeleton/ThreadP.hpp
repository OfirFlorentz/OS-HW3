//
// Created by student on 12/28/20.
//

#ifndef WET3_FILES_THREADP_H
#define WET3_FILES_THREADP_H

#include "Thread.hpp"

class ThreadP: public Thread{
public:
    ThreadP(uint thread_id);
    void thread_workload() override {
        cout << 1 << endl;
        m_ended = true;
    }
};

#endif //WET3_FILES_THREADP_H



