//
// Created by Timothy Shull on 12/25/15.
//

#include "8_15.h"
#include <iostream>

void SVBase::foo() {
    std::cout << "SVBase::foo()" << std::endl;
}

void SVDerived::foo() {
    std::cout << "SVDerived::foo()" << std::endl;
}


void testCallSClassVirtual() {
    SVDerived* p = new SVDerived();

    p->foo();
    p->SVBase::foo();
}
