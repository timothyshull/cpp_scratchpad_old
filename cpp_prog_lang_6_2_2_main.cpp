//
// Created by Timothy Shull on 1/4/16.
//

#include "6_2_2.h"
#include <cassert>
#include <iostream>

int main() {
    f(1, 2);
    f(10, 10);

    File* test_file = new File("test.txt");
//    assert(is_open(test_file));
//    std::cout << "is_open works as a simple predicate\n";

    assert(greater(10, 9));
    assert(!greater(9, 10));

    bool b1 = 7;

    try {
        bool b2 {7}; // error: narrowing
    } catch (...) {
        std::cout << "{}-initializer to bool from int triggers narrowing error" << std::endl;
    }
    exit(0);
}