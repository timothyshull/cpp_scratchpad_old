//
// Created by Timothy Shull on 12/3/15.
//

#ifndef TEST_CLASS_TESTCLASS_H
#define TEST_CLASS_TESTCLASS_H

class TestClass {
public:
    TestClass();
    TestClass(int);
    ~TestClass();
    int get_x();
    void set_x(int);
private:
    int x;
};

#endif //TEST_CLASS_TESTCLASS_H
