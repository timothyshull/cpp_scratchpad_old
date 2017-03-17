//
// Created by Timothy Shull on 12/19/15.
//

#ifndef CPPCOOKBOOK_4_3_H
#define CPPCOOKBOOK_4_3_H

#include <string>

template<typename T>
void rtrim(std::basic_string<T>& str, T c) {
    if (str.empty())
        return;

    std::basic_string<T>::iterator p;
    for (p = str.end(); p != str.begin() && *--p == c;);

    if (*p != c)
        p++;

    str.erase(p, str.end());
}

#endif //CPPCOOKBOOK_4_3_H
