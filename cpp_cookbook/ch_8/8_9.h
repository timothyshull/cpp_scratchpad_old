//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_9_H
#define CPP_COOKBOOK_8_9_H

class Singleton {
    static Singleton* inst_;

    Singleton() : value_{0} { }

    Singleton& operator=(const Singleton&);

public:
    static Singleton* getInstance();

    int getValue_() const;

    void setValue(int);

protected:
    int value_;
};

#endif //CPP_COOKBOOK_8_9_H
