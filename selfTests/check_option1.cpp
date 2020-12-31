//
// Created by student on 12/31/20.
//
# include "../Code_Skeleton/Headers.hpp"
# include "../Code_Skeleton/ThreadP.hpp"

// Data Structures:
#include <vector>
#include <string>
#include <queue>
#include <iterator>

// Streams  & Filesystem:
#include <fstream>
#include <iostream>
#include <sstream>

// Utility
#include <cmath>
#include <cassert>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <unistd.h>

// Threads & Synchronization
#include <pthread.h>



int main() {
    vector<Thread*> m_threadpool;
    int size = 5;

    for (uint i = 0; i < size; ++i) {
        ThreadP * thr = new ThreadP(i);
        m_threadpool.push_back(thr);
    }
    cout << "pass creating the threads" << endl;

    for (int i = 0; i < size; ++i) {
        m_threadpool[i]->start();
    }

    cout << "quick printing running the threads (does not means the running was complete)" << endl;


    for (int i = 0; i < size; ++i) {
        m_threadpool[i]->join();
    }
    cout << "pass joining the threads" << endl;

    cout << "******************* finish *******************" << endl;


    return 0;
}