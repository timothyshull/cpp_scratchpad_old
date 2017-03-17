//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_6_8_H
#define CPPCOOKBOOK_6_8_H

#include <string>

struct strPtrLess {
    bool operator()(const std::string*, const std::string*);
};

void sortedSet();

#endif //CPPCOOKBOOK_6_8_H
