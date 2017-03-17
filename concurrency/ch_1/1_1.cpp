//
// Created by Timothy Shull on 12/22/15.
//

#include "1_1.h"
#include <iostream>

void hello() {
    std::cout << "concurrent stuff" << std::endl;
}

void hello::operator()() {
    std::cout << "concurrent stuff" << std::endl;
}
