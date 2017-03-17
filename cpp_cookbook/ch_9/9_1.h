//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_9_1_H
#define CPP_COOKBOOK_9_1_H

#include <string>

class CustomException {
public:
    CustomException(const std::string& msg) : msg_{msg} { }

    ~CustomException() { }

    const std::string& getMsg() const;

private:
    std::string msg_;
};

void throwCustom();

void tryThrowing();

#endif //CPP_COOKBOOK_9_1_H
