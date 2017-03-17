//
// Created by Timothy Shull on 12/18/15.
//

#ifndef CPPCOOKBOOK_3_5_H
#define CPPCOOKBOOK_3_5_H

#include <iostream>
#include <boost/lexical_cast.hpp>

template<typename T>
bool isValid(const std::string& num) {
    bool res = true;

    try {
        T tmp = boost::lexical_cast<T>(num);
    } catch (boost::bad_lexical_cast& e) {
        res = false;
    }

    return res;
}

void test(const std::string& s) {
    if (isValid<int>(s)) {
        std::cout << s << " is a valid integer." << std::endl;
    } else {
        std::cout << s << " is not a valid integer." << std::endl;
    }

    if (isValid<double>(s)) {
        std::cout << s << " is a valid double." << std::endl;
    } else {
        std::cout << s << " is not a valid double." << std::endl;
    }

    if (isValid<float>(s)) {
        std::cout << s << " is a valid float." << std::endl;
    } else {
        std::cout << s << " is not a valid float." << std::endl;
    }
}

#endif //CPPCOOKBOOK_3_5_H
