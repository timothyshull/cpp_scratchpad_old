//
// Created by Timothy Shull on 12/3/15.
//

#include "TestClass.h"

TestClass::TestClass() : x {1} { }

TestClass::TestClass(int a) : x {a} { }

TestClass::~TestClass() { }

int TestClass::get_x() {
    return x;
}

void TestClass::set_x(int a) {
    x = a;
}