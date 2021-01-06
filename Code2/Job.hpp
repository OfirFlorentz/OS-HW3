//
// Created by student on 1/5/21.
//

#ifndef GITCODE_JOB_H
#define GITCODE_JOB_H


class Job {
    int start_line;
    int num_of_lines;
    bool last_call;

public:
    Job(int start_line, int num_of_lines, bool last_call = false);
    ~Job()=default;
    int get_start_line();
    int get_num_of_lines();
    bool get_is_last_call();
};


#endif //GITCODE_JOB_H
