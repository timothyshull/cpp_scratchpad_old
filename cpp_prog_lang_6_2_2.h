//
// Created by Timothy Shull on 1/4/16.
//

#ifndef CPP_PROGRAMMING_LANGUAGE_EXAMPLES_6_2_2_H
#define CPP_PROGRAMMING_LANGUAGE_EXAMPLES_6_2_2_H

#include <fstream>

void f(int, int);

class File {
    friend bool is_open(File*);

    std::fstream filestream;
public:
    File(std::string);
};

bool is_open(File*);

bool greater(int, int);

void f(int);

void g(int*);

#endif //CPP_PROGRAMMING_LANGUAGE_EXAMPLES_6_2_2_H
