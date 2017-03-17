//
// Created by Timothy Shull on 12/25/15.
//

#include "9_1.h"
#include <iostream>

const std::string& CustomException::getMsg() const {
    return msg_;
}

void throwCustom() {
    throw (CustomException("Mr. Sulu"));
}

void tryThrowing() {
    try {
        throwCustom();
    } catch (CustomException& e) {
        std::cout << "You threw an exception: " << e.getMsg() << std::endl;
    }
}
