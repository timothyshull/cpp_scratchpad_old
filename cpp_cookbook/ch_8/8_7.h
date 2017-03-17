//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_7_H
#define CPP_COOKBOOK_8_7_H

class Base2 {
public:
    virtual ~Base2() { }
};

class Derived2 : public Base2 {
public:
    virtual ~Derived2() { }
};

void testClassRelationship();

#endif //CPP_COOKBOOK_8_7_H
