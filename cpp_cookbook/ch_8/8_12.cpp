//
// Created by Timothy Shull on 12/25/15.
//

#include "8_12.h"

template<typename T>
T* ObjectManager::gimmeAnObject() {
    return new T;
}

template<typename T>
void ObjectManager::gimmeAnObject(T*& p) {
    p = new T;
}

void testMemberTemplate() {
    ObjectManager om;
    X* p1 = om.gimmeAnObject<X>();
    Y* p2 = om.gimmeAnObject<Y>();

    om.gimmeAnObject(p1);
    om.gimmeAnObject(p2);
}
