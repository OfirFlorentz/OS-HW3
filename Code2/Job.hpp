//
// Created by student on 1/5/21.
//

#ifndef GITCODE_JOB_H
#define GITCODE_JOB_H


class Job {
    int start_line;
    int num_of_lines;

public:
    Job(int start_line, int num_of_lines);
    ~Job()=default;
    int get_start_line();
    int get_num_of_lines();
};


#endif //GITCODE_JOB_H
