//
// Created by Timothy Shull on 12/24/15.
//

#ifndef CPP_COOKBOOK_8_1_H
#define CPP_COOKBOOK_8_1_H

#include <string>

class Foo {
    int counter_;
    std::string* str_;
public:
    Foo() : counter_(0), str_(nullptr) { }

    Foo(int counter_, std::string* str_) : counter_(counter_), str_(str_) { }
};

void tryInstantiate();

#endif //CPP_COOKBOOK_8_1_H
