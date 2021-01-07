//
// Created by student on 1/5/21.
//

#ifndef GITCODE_JOB_H
#define GITCODE_JOB_H


class Job {
    bool phase1;
    int start_line;
    int num_of_lines;
    bool last_call;

public:
    Job(bool phase1, int start_line, int num_of_lines, bool last_call);
    ~Job()=default;
    bool get_which_phase();
    int get_start_line();
    int get_num_of_lines();
    bool get_is_last_call();
};


#endif //GITCODE_JOB_H
