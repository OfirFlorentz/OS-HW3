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
    p1.n_thread = 5;
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

void test3 () {
    cout << "************ start test3 ************" << endl;
    struct game_params p1;
    p1.n_gen = 3;
    p1.filename = "../selfBoards/random_board1.txt";
    p1.interactive_on = false;
    p1.print_on = true;
    p1.n_thread = 18;

    Game* g = new Game(p1);
    g->run();

    cout << "************ finish test3 ************\n" << endl;
}

void test4 () {
    cout << "************ start test4 ************" << endl;
    struct game_params p1;
    p1.n_gen = 2;
    p1.filename = "../selfBoards/random_board2.txt";
    p1.interactive_on = false;
    p1.print_on = true;
    p1.n_thread = 10;

    Game* g = new Game(p1);
    g->run();

    cout << "************ finish test4 ************\n" << endl;
}

void test5 () {
    cout << "************ start test5 ************" << endl;
    struct game_params p1;
    p1.n_gen = 5;
    p1.filename = "../selfBoards/random_board3.txt";
    p1.interactive_on = false;
    p1.print_on = true;
    p1.n_thread = 10;

    Game* g = new Game(p1);
    g->run();

    cout << "************ finish test5 ************\n" << endl;
}


int main() {
    test1();
//    test2();
//    test3();
//    test4();
//    test5();



    return 0;
}