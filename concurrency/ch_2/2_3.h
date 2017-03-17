//
// Created by Timothy Shull on 12/27/15.
//

#ifndef PROJECT_2_3_H
#define PROJECT_2_3_H

#include <thread>

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t{t_} { }

    ~thread_guard();

    thread_guard(const thread_guard &) = delete;

    thread_guard& operator=(const thread_guard &) = delete;
};

void test_thread_guard();

#endif //PROJECT_2_3_H
