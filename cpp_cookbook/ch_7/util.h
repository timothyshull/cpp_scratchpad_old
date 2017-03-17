//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_UTIL_H_H
#define CPPCOOKBOOK_UTIL_H_H

#include <iostream>
#include <ostream>
#include <vector>

namespace cbook_util {
    template<typename T>
    void printRange(T first, T last, char delim = ',', std::ostream& out = std::cout) {
        out << "{";
        while (first != last) {
            out << *first;
            if (++first != last)
                out << delim << ' ';
        }
        out << "}" << std::endl;
    }

    template<typename T>
    void printContainer(const T& t, char delim = ',', std::ostream& out = std::cout) {
        printRange<typename T::const_iterator>(t.begin(), t.end(), delim, out);
    }
}

#endif //CPPCOOKBOOK_UTIL_H_H
