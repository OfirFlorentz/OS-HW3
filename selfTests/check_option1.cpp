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
    vector<int> tmp1 = {1,0,0,3,0,0,0,0};
    vector<int> tmp2 = {1,0,1,0,0,0,0,2};
    vector<int> tmp3 = {0,0,0,3,0,0,0,0};
    vector<int> tmp4 = {0,0,0,5,7,0,0,1};
    vector<int> tmp5 = {0,0,6,5,5,0,0,0};

    vector<vector<int>> board1 = {tmp1, tmp2, tmp3, tmp4, tmp5};
    vector<vector<int>> next_board = board1;

    vector<Thread*> m_threadpool;
    int size = 1;

    for (uint i = 0; i < size; ++i) {

        ThreadP * thr = new ThreadP(0, board1, next_board, 0, 5);;
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
    cout << "pass joining the threads\n" << endl;
    cout << "the new board is: " << endl;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << next_board[i][j];
        }
        cout << endl;
    }

    cout << "******************* finish *******************" << endl;


    return 0;
}