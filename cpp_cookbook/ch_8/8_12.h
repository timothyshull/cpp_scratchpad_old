//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_12_H
#define CPP_COOKBOOK_8_12_H

class ObjectManager {
public:
    template<typename T>
    T* gimmeAnObject();

    template<typename T>
    void gimmeAnObject(T*& p);
};

class X {
};

class Y {
};

void testMemberTemplate();

#endif //CPP_COOKBOOK_8_12_H
