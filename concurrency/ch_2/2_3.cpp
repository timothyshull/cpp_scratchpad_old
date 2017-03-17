//
// Created by Timothy Shull on 12/27/15.
//

#include "2_3.h"
#include "2_1.h"
#include <iostream>

thread_guard::~thread_guard() {
    if (t.joinable())
        t.join();
}

void test_thread_guard() {
    int some_local_state{0};
    func my_func{some_local_state};
    std::thread t{my_func};
    thread_guard g{t};

    std::cout << "do something in current thread" << std::endl;
}
