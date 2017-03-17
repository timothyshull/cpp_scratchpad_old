//
// Created by Timothy Shull on 12/25/15.
//

#include "8_6.h"
#include <iostream>

void testTypeId() {
    Base b, bb;
    Derived d;

    if (typeid(b) == typeid(d)) {
        std::cout << "b and d are the same type." << std::endl;
    }
    if (typeid(b) == typeid(bb)) {
        std::cout << "b and bb are the same type." << std::endl;
    }
    if (typeid(b) == typeid(Derived)) {
        std::cout << "d is the Derived type." << std::endl;
    }
}
