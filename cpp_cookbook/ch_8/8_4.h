//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_4_H
#define CPP_COOKBOOK_8_4_H

#include <list>

class MyClass {
protected:
    int value_;
public:
    static std::list<MyClass*> instances_;

    MyClass(int);

    ~MyClass();

    static void showList();
};

void testStoreInstances();

#endif //CPP_COOKBOOK_8_4_H
