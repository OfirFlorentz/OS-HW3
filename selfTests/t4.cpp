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

vector<float> m_tile_hist;
pthread_mutex_t m_mutex;

static void print_board(vector<vector<int>> board) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void test1 () {
    cout << "************ start test1 ************" << endl;
    vector<int> tmp1 = {1,2,0,3,0,0,0,0};
    vector<int> tmp2 = {1,3,1,0,0,0,0,2};
    vector<int> tmp3 = {0,0,0,3,0,0,0,0};
    vector<int> tmp4 = {0,0,0,5,7,0,0,1};
    vector<int> tmp5 = {0,0,6,5,5,0,0,0};

    vector<vector<int>> board1 = {tmp1, tmp2, tmp3, tmp4, tmp5};
    vector<vector<int>> next_board = board1;

    ThreadP* t = new ThreadP(0, &board1, &next_board, 0, 5, &m_tile_hist, &m_mutex);
    t->start();
    t->join();

    print_board(next_board);
    cout << "************ finish test1 ************\n" << endl;
}

void test2 () {
    cout << "************ start test2 ************" << endl;
    vector<int> tmp1 = {1,1,1,1,1,1,1,1};
    vector<int> tmp2 = {1,1,1,1,1,1,1,1};
    vector<int> tmp3 = {1,1,1,1,1,1,1,1};
    vector<int> tmp4 = {1,1,1,1,1,1,1,1};
    vector<int> tmp5 = {1,1,1,1,1,1,1,1};


    vector<vector<int>> board1 = {tmp1, tmp2, tmp3, tmp4, tmp5};
    vector<vector<int>> next_board = board1;

    ThreadP* t = new ThreadP(0, &board1, &next_board, 0, 5, &m_tile_hist, &m_mutex);
    t->start();
    t->join();

    print_board(next_board);
    cout << "************ finish test2 ************\n" << endl;
}

void test3 () {
    cout << "************ start test3 ************" << endl;
    vector<int> tmp1 = {1,1,1,1,1,1,3,3};
    vector<int> tmp2 = {1,1,0,0,0,1,3,3};
    vector<int> tmp3 = {1,1,0,0,0,1,1,1};
    vector<int> tmp4 = {2,2,1,1,1,1,1,1};
    vector<int> tmp5 = {2,2,1,1,1,1,1,1};


    vector<vector<int>> board1 = {tmp1, tmp2, tmp3, tmp4, tmp5};
    vector<vector<int>> next_board = board1;

    ThreadP* t = new ThreadP(0, &board1, &next_board, 0, 5, &m_tile_hist, &m_mutex);
    t->start();
    t->join();

    print_board(next_board);
    cout << "************ finish test3 ************\n" << endl;
}

void test4 () {
    cout << "************ start test4 ************" << endl;
    vector<int> tmp1 = {1,1,1,0,1,0,1,1};
    vector<int> tmp2 = {0,1,0,1,0,1,0,1};
    vector<int> tmp3 = {0,1,0,2,0,3,0,1};
    vector<int> tmp4 = {0,7,0,1,0,2,0,1};
    vector<int> tmp5 = {7,0,1,1,2,0,1,1};


    vector<vector<int>> board1 = {tmp1, tmp2, tmp3, tmp4, tmp5};
    vector<vector<int>> next_board = board1;

    ThreadP* t = new ThreadP(0, &board1, &next_board, 0, 5, &m_tile_hist, &m_mutex);
    t->start();
    t->join();

    print_board(next_board);
    cout << "************ finish test4 ************\n" << endl;
}

void test5 () {
    cout << "************ start test5 ************" << endl;
    vector<int> tmp1 = {1,1,1,0,1,0,1,1};
    vector<int> tmp2 = {0,1,0,1,0,1,0,1};
    vector<int> tmp3 = {0,1,0,2,0,3,0,1};
    vector<int> tmp4 = {0,7,0,1,0,2,0,1};
    vector<int> tmp5 = {7,0,1,1,2,0,1,1};
    vector<int> tmp6 = {7,0,1,1,2,0,1,1};
    vector<int> tmp7 = {7,0,1,1,2,0,1,1};


    vector<vector<int>> board1 = {tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7};
    vector<vector<int>> next_board = board1;

    ThreadP* t1 = new ThreadP(0, &board1, &next_board, 1, 3, &m_tile_hist, &m_mutex);
    ThreadP* t2 = new ThreadP(0, &board1, &next_board, 5, 1, &m_tile_hist, &m_mutex);

    t1->start();
    t2->start();
    t1->join();
    t2->join();

    print_board(next_board);
    cout << "************ finish test5 ************\n" << endl;
}

void test6 () {
    cout << "************ start test6 ************" << endl;
    vector<int> tmp0 = {1,1,1,0,1,0,1,1,7};
    vector<int> tmp1 = {1,1,5,0,1,0,1,1,0};
    vector<int> tmp2 = {0,1,0,1,0,1,2,1,3};
    vector<int> tmp3 = {0,1,3,2,0,3,0,1,2};
    vector<int> tmp4 = {0,7,0,1,0,2,0,1,0};
    vector<int> tmp5 = {7,0,1,1,2,6,1,1,0};
    vector<int> tmp6 = {7,3,1,1,2,0,3,1,5};
    vector<int> tmp7 = {7,0,1,1,2,7,1,1,0};


    vector<vector<int>> board1 = {tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7};
    vector<vector<int>> next_board = board1;

    ThreadP* t1 = new ThreadP(0, &board1, &next_board, 0, 3, &m_tile_hist, &m_mutex);
    ThreadP* t2 = new ThreadP(0, &board1, &next_board, 3, 3, &m_tile_hist, &m_mutex);
    ThreadP* t3 = new ThreadP(0, &board1, &next_board, 6, 2, &m_tile_hist, &m_mutex);

    t1->start();
    t1->join();
    print_board(next_board);
    cout << endl;

    t2->start();
    t2->join();
    print_board(next_board);
    cout << endl;

    t3->start();
    t3->join();
    print_board(next_board);

    cout << "************ finish test6 ************\n" << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}