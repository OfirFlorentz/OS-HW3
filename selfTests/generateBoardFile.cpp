//
// Created by student on 1/1/21.
//
#include <random>
// Streams  & Filesystem:
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main(){

    int row = 1 + (rand() % 100);
    int col = 1 + (rand() % 200);

    ofstream m_file("random_board3.txt");

    for (int i = 0; i < row; ++i) {

        for (int j = 0; j < col; ++j) {
            int val = rand() % 2 == 1 ? 0 : rand() % 8;
            m_file << val;
            if (j != col-1) m_file << " ";
        }
        if (i != row-1) m_file << "\n";
    }
    m_file.close();

    return 0;
}

