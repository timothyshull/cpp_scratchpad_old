//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_9_2_H
#define CPP_COOKBOOK_9_2_H

#include <exception>
#include <string>

class Device {
public:
    Device(int);

    ~Device();
};

class Broker {
public:
    Broker(int, int);

    ~Broker();

private:
    Broker();

    Device* dev1_;
    Device* dev2_;
};

class basic_error : public std::exception {
public:
    basic_error(std::string str) : str_(str) { }

    virtual const char* what() const throw();

private:
    std::string str_;
};

void tryExceptionSafeCtor();

#endif //CPP_COOKBOOK_9_2_H
