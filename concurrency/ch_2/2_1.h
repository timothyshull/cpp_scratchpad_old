//
// Created by Timothy Shull on 12/27/15.
//

#ifndef PROJECT_2_1_H
#define PROJECT_2_1_H

struct func {
    int& i;

    func(int& i_) : i{i_} { }

    void operator()();
};

void oops();

#endif //PROJECT_2_1_H
