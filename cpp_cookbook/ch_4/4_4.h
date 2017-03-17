//
// Created by Timothy Shull on 12/19/15.
//

#ifndef CPPCOOKBOOK_4_4_H
#define CPPCOOKBOOK_4_4_H

#include <string>

template<typename T, typename F>
void rtrimws(std::basic_string<T>& str, F f) {
    if (str.empty())
        return;

    std::basic_string<T>::iterator p;
    for (p = str.end(); p != str.begin() && f(*--p););

    if (!f(*p))
        p++;

    str.erase(p, str.end());
}

#endif //CPPCOOKBOOK_4_4_H
