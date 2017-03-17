//
// Created by Timothy Shull on 12/20/15.
//

#include "7_8.h"
#include "util.h"
#include <set>

void setOperations() {
    std::cout << "Enter some strings: " << std::endl;
    std::istream_iterator<std::string> start{std::cin};
    std::istream_iterator<std::string> end;
    std::set<std::string> s1{start, end};
    std::cin.clear();

    std::cout << "Enter some more strings: " << std::endl;
    std::set<std::string> s2{++start, end};

    std::set<std::string> setUnion;
    std::set<std::string> setInter;
    std::set<std::string> setDiff;

    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(setUnion, setUnion.begin()));
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(setDiff, setDiff.begin()));
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(setInter, setInter.begin()));

    std::cout << "Union: " << std::endl;
    cbook_util::printContainer(setUnion);
    std::cout << "Union: " << std::endl;
    cbook_util::printContainer(setDiff);
    std::cout << "Union: " << std::endl;
    cbook_util::printContainer(setInter);
}
