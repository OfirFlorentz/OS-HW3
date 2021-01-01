//
// Created by student on 1/1/21.
//
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

#include <fstream>
#include <iostream>
#include <string.h>

# include "../Code_Skeleton/Headers.hpp"
# include "../Code_Skeleton/ThreadP.hpp"
# include "../Code_Skeleton/Game.hpp"

using namespace std;


bool compare_boards(string output, string expected) {
    ifstream output_f,expected_f;
    output_f.open(output);
    expected_f.open(expected);

    std::string string1, string2;
    int num_of_diff = 0;
    int i = 1;
    while(std::getline(expected_f, string2)) {
        std::getline(output_f, string1);
        if(string1 != string2) {
            std::cout << "difference encountered on " << i << " line" << endl;
            std::cout << "+ " << string1 << endl;
            std::cout << "- " << string2 << endl;
            if (++num_of_diff > 222) {
                std::cout << "too much differents... stops test" << endl;
                break;
            }
        }
        ++i;
    }
    return num_of_diff == 0;
}

bool testSmallSegel () {

    cout << "************ start test ************" << endl;
    cout << "****** small board from Segal *******" << endl;
    struct game_params p1;
    p1.n_gen = 10;
    p1.n_thread = 5;
    p1.filename = "../selfBoards/small.txt";
    p1.interactive_on = false;
    p1.print_on = true;

    Game* g = new Game(p1);

    std::ofstream out("tester_output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout

    g->run();

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();

    bool res = compare_boards("../selfBoards/expect_board1.txt", "tester_output.txt");
    if (res) {
        cout << "****** finish test with success! ******\n" << endl;
        return true;
    }
    else {
        cout << "****** finish test but without success... sorry, maybe next time ******\n" << endl;
        return false;
    }
}

bool test1 () {

    cout << "************ start test1 ************" << endl;
    cout << "*********** random board1 ***********" << endl;
    struct game_params p1;
    p1.n_gen = 10;
    p1.n_thread = 9;
    p1.filename = "../selfBoards/random_board1.txt";
    p1.interactive_on = false;
    p1.print_on = true;

    Game* g = new Game(p1);

    std::ofstream out("tester_output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout

    g->run();

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();

    bool res = compare_boards("../selfBoards/random_board1_expected.txt", "tester_output.txt");
    if (res) {
        cout << "****** finish test1 with success! ******\n" << endl;
        return true;
    }
    else {
        cout << "****** finish test1 but without success... sorry, maybe next time ******\n" << endl;
        return false;
    }
}

bool test2 () {

    cout << "************ start test2 ************" << endl;
    cout << "*********** random board2 ***********" << endl;
    struct game_params p1;
    p1.n_gen = 5;
    p1.n_thread = 11;
    p1.filename = "../selfBoards/random_board2.txt";
    p1.interactive_on = false;
    p1.print_on = true;

    Game* g = new Game(p1);

    std::ofstream out("tester_output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout

    g->run();

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();

    bool res = compare_boards("../selfBoards/random_board2_expected.txt", "tester_output.txt");
    if (res) {
        cout << "****** finish test2 with success! ******\n" << endl;
        return true;
    }
    else {
        cout << "****** finish test2 but without success... sorry, maybe next time ******\n" << endl;
        return false;
    }
}

int main () {
    testSmallSegel();
    test1();
    test2();
}

