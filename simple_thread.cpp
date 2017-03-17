//
//  main.cpp
//  threads
//
//  Created by Tim Shull on 10/15/16.
//  Copyright © 2016 Tim Shull. All rights reserved.
//

#include <iostream>
#include <thread>

void do_something(int &i) {
    ++i;
}

struct func {
    int &i;

    func(int &i_) : i(i_) {
    }

    void operator()() {
        for (unsigned j = 0; j < 1000000; ++j) {
            do_something(i);
        }
    }
};


void oops() {
    int some_local_state = 0;
    func current_func(some_local_state);
    std::thread current_thread(current_func);
    current_thread.detach();
}

int main() {
    oops();
    return 0;
}
