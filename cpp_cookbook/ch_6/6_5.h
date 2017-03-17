//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_6_5_H
#define CPPCOOKBOOK_6_5_H

#include <iostream>

template<typename T>
struct printer {
    void operator()(const T& s) {
        std::cout << s << std::endl;
    }
};

bool inline even(int n) { return n % 2 == 0; }

void storeList();

#endif //CPPCOOKBOOK_6_5_H
