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

void test1 () {
    cout << "************ start test1 ************" << endl;
    vector<int> tmp1 = {1,0,0,3,0,0,0,0};
    vector<int> tmp2 = {1,0,1,0,0,0,0,2};
    vector<int> tmp3 = {0,0,0,3,0,0,0,0};
    vector<int> tmp4 = {0,0,0,5,7,0,0,1};
    vector<int> tmp5 = {0,0,6,5,5,0,0,0};

    vector<vector<int>> board1 = {tmp1, tmp2, tmp3, tmp4, tmp5};
    vector<vector<int>> next_board = board1;

    ThreadP* t = new ThreadP(0,board1,next_board,0,5);
    t->start();
    t->join();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << next_board[i][j];
        }
        cout << endl;
    }
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

    ThreadP* t = new ThreadP(0,board1,next_board,0,5);
    t->start();
    t->join();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << next_board[i][j];
        }
        cout << endl;
    }
    cout << "************ finish test2 ************\n" << endl;
}

void test3 () {
    cout << "************ start test3 ************" << endl;
    vector<int> tmp1 = {1,1,1,1,1,1,3,3};
    vector<int> tmp2 = {1,1,1,0,0,1,3,3};
    vector<int> tmp3 = {1,1,1,0,0,1,1,1};
    vector<int> tmp4 = {2,2,1,1,1,1,1,1};
    vector<int> tmp5 = {2,2,1,1,1,1,1,1};


    vector<vector<int>> board1 = {tmp1, tmp2, tmp3, tmp4, tmp5};
    vector<vector<int>> next_board = board1;

    ThreadP* t = new ThreadP(0,board1,next_board,0,5);
    t->start();
    t->join();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << next_board[i][j];
        }
        cout << endl;
    }
    cout << "************ finish test3 ************\n" << endl;
}


int main() {
    test1();
    test2();
    test3();




    return 0;
}