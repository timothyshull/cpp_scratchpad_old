//
// Created by Timothy Shull on 12/25/15.
//

#include "8_5.h"
#include <iostream>

int OneStatic::count = 0;

OneStatic::OneStatic() {
    count++;
}

void testOneStatic() {
    OneStatic a;
    OneStatic b;
    OneStatic c;

    std::cout << a.getCount() << std::endl;
    std::cout << b.getCount() << std::endl;
    std::cout << c.getCount() << std::endl;
}
