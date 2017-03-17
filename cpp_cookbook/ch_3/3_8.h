//
// Created by Timothy Shull on 12/19/15.
//

#ifndef CPPCOOKBOOK_3_8_H
#define CPPCOOKBOOK_3_8_H

#include <iostream>
#include <boost/cast.hpp>

// Pointless wrapper
template<typename T, typename I>
T safe_numeric_cast(I input) {
    T out;
    try {
        out = boost::numeric_cast<T>(input);
    } catch (boost::bad_numeric_cast& e) {
        std::cerr << e.what() << std::endl;
    }
    return out;
};

#endif //CPPCOOKBOOK_3_8_H
