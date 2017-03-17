//
// Created by Timothy Shull on 12/25/15.
//

#include "8_4.h"
#include <iostream>

std::list<MyClass*> MyClass::instances_;

MyClass::MyClass(int val) {
    instances_.push_back(this);
    value_ = val;
}

MyClass::~MyClass() {
    std::list<MyClass*>::iterator p = std::find(instances_.begin(), instances_.end(), this);
    if (p != instances_.end())
        instances_.erase(p);
}

void MyClass::showList() {
    for (std::list<MyClass*>::iterator p = instances_.begin(); p != instances_.end(); ++p)
        std::cout << (*p)->value_ << std::endl;
}

void testStoreInstances() {
    MyClass a(1);
    MyClass b(10);
    MyClass c(100);
    MyClass::showList();
}
