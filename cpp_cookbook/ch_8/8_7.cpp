//
// Created by Timothy Shull on 12/25/15.
//

#include "8_7.h"
#include <iostream>

void testClassRelationship() {
    Derived2 d;

    if (dynamic_cast<Base2*>(&d)) {
        std::cout << "Derived 2is a subclass of Base2" << std::endl;
    } else {
        std::cout << "Derived2 is not a buclass of Base2" << std::endl;
    }

}
