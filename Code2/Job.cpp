//
// Created by student on 1/5/21.
//

#include "Job.hpp"

Job::Job(int start_line, int num_of_lines) : start_line(start_line), num_of_lines(num_of_lines) {}

int Job::get_start_line() {
    return start_line;
}

int Job::get_num_of_lines() {
    return num_of_lines;
}

