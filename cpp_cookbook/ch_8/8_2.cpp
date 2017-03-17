//
// Created by Timothy Shull on 12/24/15.
//

#include "8_2.h"

Session SessionFactory::Create() {
    return Session();
}

Session* SessionFactory::CreatePtr() {
    return new Session();
}

void SessionFactory::Create(Session*& p) {
    p = new Session();
}

static SessionFactory f;

void trySessionFactory() {
    Session* p1;
    Session* p2 = new Session();
    *p2 = f.Create();
    p1 = f.CreatePtr();
}
