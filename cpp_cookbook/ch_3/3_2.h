//
// Created by Timothy Shull on 12/18/15.
//

#ifndef CPPCOOKBOOK_3_2_H
#define CPPCOOKBOOK_3_2_H

#include <string>
#include <boost/lexical_cast.hpp>

template<typename T>
T str2num(const std::string& str) {
    return boost::lexical_cast<T>(str);
}

#endif //CPPCOOKBOOK_3_2_H
