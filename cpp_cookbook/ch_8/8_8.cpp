//
// Created by Timothy Shull on 12/25/15.
//

#include "8_8.h"
#include <iostream>

int UniqueID::nextID = 0;

UniqueID::UniqueID() {
    id = ++nextID;
}

UniqueID::UniqueID(const UniqueID& orig) {
    id = orig.id;
}

UniqueID& UniqueID::operator=(const UniqueID& orig) {
    id = orig.id;
    return *this;
}

void testClassID() {
    UniqueID a;
    std::cout << a.id << std::endl;
    UniqueID b;
    std::cout << b.id << std::endl;
    UniqueID c;
    std::cout << c.id << std::endl;
}
