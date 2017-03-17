//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_6_3_H
#define CPPCOOKBOOK_6_3_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<typename T>
void vecPrint(const std::vector<T>& vec) {
    std::cout << "{";
    for (typename std::vector<T>::const_iterator p = vec.begin(); p != vec.end(); ++p)
        std::cout << "{" << *p << "}";

    std::cout << "}" << std::endl;
}

void copyVector();

#endif //CPPCOOKBOOK_6_3_H
