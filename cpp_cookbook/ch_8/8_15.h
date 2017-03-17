//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_15_H
#define CPP_COOKBOOK_8_15_H

class SVBase {
public:
    virtual void foo();
};

class SVDerived : public SVBase {
public:
    virtual void foo();
};

void testCallSClassVirtual();

#endif //CPP_COOKBOOK_8_15_H
