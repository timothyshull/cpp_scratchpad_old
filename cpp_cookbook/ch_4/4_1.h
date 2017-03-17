//
// Created by Timothy Shull on 12/19/15.
//

#ifndef CPPCOOKBOOK_4_1_H
#define CPPCOOKBOOK_4_1_H

#include <string>

template<typename T>
void pad(std::basic_string<T>& s,
         typename std::basic_string<T>::size_type n,
         T c) {
    if (n > s.length())
        s.append(n - s.length(), c);
}

#endif //CPPCOOKBOOK_4_1_H
