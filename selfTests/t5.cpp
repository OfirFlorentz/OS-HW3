//
// Created by student on 12/31/20.
//
# include "../Code_Skeleton/Headers.hpp"
# include "../Code_Skeleton/ThreadP.hpp"
# include "../Code_Skeleton/Game.hpp"
# include "../Code_Skeleton/utils.hpp"

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
    struct game_params p1;
    p1.n_gen = 10;
    p1.n_thread = 2;
    p1.filename = "../Tools/example_IO_files/small.txt";
    p1.interactive_on = false;
    p1.print_on = true;

    Game* g = new Game(p1);
    g->run();

    cout << "************ finish test1 ************\n" << endl;
}

void test2 () {
    cout << "************ start test2 ************" << endl;
    struct game_params p1;
    p1.n_gen = 5;
    p1.filename = "../selfBoards/b1.txt";
    p1.interactive_on = false;
    p1.print_on = true;

    for (int i = 1; i < 7; ++i) {
        p1.n_thread = i;
        Game* g = new Game(p1);
        g->run();
    }

    cout << "************ finish test2************\n" << endl;
}


int main() {
//    test1();
    test2();


    return 0;
}