//
// Created by Timothy Shull on 12/19/15.
//

#include "4_2.h"

void rtrim(std::string& str, char c) {
    if (str.empty())
        return;

    std::string::iterator p;
    for (p = str.end(); p != str.begin() && *--p == c;);

    if (*p != c)
        p++;

    str.erase(p, str.end());
}
