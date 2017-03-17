//
// Created by Timothy Shull on 12/19/15.
//

#ifndef CPPCOOKBOOK_3_7_H
#define CPPCOOKBOOK_3_7_H

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
T sciToDouble(const std::string& str) {
    std::stringstream ss{str};
    T d = 0;
    ss >> d;

    if (ss.fail()) {
        std::string s = "Unable to format ";
        s += str;
        s += " as a number.";
        throw s;
    }

    return d;
}

#endif //CPPCOOKBOOK_3_7_H
