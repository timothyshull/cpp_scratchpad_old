//
// Created by Timothy Shull on 12/20/15.
//

#include "6_7.h"
#include <iostream>
#include <unordered_set>

// prefer unordred_set over hash_set

void strsInHashSet() {
    std::unordered_set<std::string> hsString;
    std::string s{"bravo"};

    hsString.insert(s);
    s = "alpha";
    hsString.insert(s);
    s = "charlie";
    hsString.insert(s);

    for (auto str : hsString)
        std::cout << str << std::endl;
}
