//
// Created by Timothy Shull on 12/24/15.
//

#ifndef CPP_COOKBOOK_8_2_H
#define CPP_COOKBOOK_8_2_H

class Session {
    static int count_;
    int sessionId_;
public:
    Session();
};

class SessionFactory {
public:
    Session Create();

    Session* CreatePtr();

    void Create(Session*& p);
};

void trySessionFactory();

#endif //CPP_COOKBOOK_8_2_H
