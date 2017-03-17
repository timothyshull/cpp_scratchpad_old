//
// Created by Timothy Shull on 12/27/15.
//

#include "2_1.h"
#include <iostream>
#include <thread>

void func::operator()() {
    for (unsigned j{0}; j < 1000000; j++)
        std::cout << i << "\n";
}

void oops() {
    int some_local_state{0};
    func my_func{some_local_state};
    std::thread my_thread(my_func);
    my_thread.detach();
//    my_thread.join();
}
