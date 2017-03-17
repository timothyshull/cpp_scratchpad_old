//
// Created by Timothy Shull on 11/29/15.
//

#include "types_and_declarations.h"
#include <iostream>
// #include <vector>

void compare_ints(int a, int b) {
    bool b1{a == b};

    b1 ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
}

void intval() {
    for (char c; std::cin >> c;)
        std::cout << "the value of '" << c << "' is " << int{c} << std::endl;
}

void digits() {
    for (int i = 0; i != 10; ++i)
        std::cout << static_cast<char>('0' + i) << std::endl;
}

/*
void user(const std::vector<int> &vx) {
    int buffer;
    constexpr int bufmax{1024};
    alignas(int) buffer[bufmax];

    const size_t max = std::min(vx.size(), bufmax / sizeof(int));
    uninitialized_copy(vx.begin(), vx.begin() + max, buffer);
}*/
