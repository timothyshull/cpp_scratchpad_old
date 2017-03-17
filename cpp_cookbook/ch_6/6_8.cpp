//
// Created by Timothy Shull on 12/20/15.
//

#include "6_8.h"
#include <cassert>
#include <iostream>
#include <set>

bool strPtrLess::operator()(const std::string* p1, const std::string* p2) {
    assert(p1 && p2);
    return *p1 < *p2;
}

void sortedSet() {
    std::set<std::string> setStr;
    std::string s = "Bill";

    setStr.insert(s);
    s = "Steve";
    setStr.insert(s);
    s = "Randy";
    setStr.insert(s);
    s = "Howard";
    setStr.insert(s);

    for (auto str : setStr)
        std::cout << str << std::endl;

    std::set<std::string*, strPtrLess> setStrPtr;
    std::string s1 = "Tom";
    std::string s2 = "Dick";
    std::string s3 = "Harry";

    setStrPtr.insert(&s1);
    setStrPtr.insert(&s2);
    setStrPtr.insert(&s3);

    for (auto str : setStrPtr)
        std::cout << *str << std::endl;
}
