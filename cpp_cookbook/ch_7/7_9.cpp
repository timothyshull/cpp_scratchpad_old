//
// Created by Timothy Shull on 12/20/15.
//

#include "7_9.h"
#include "util.h"
#include <list>

std::string strToUpper(const std::string& s) {
    std::string tmp;
    for (std::string::const_iterator p = s.begin(); p != s.end(); ++p)
        tmp += toupper(*p);
    return tmp;
}


std::string strAppend(const std::string& s1, const std::string& s2) {
    return s1 + s2;
}

void transformData() {
    std::cout << "Enter a series of strings: " << std::endl;
    std::istream_iterator<std::string> start{std::cin};
    std::istream_iterator<std::string> end;
    std::list<std::string> lst{start, end}, out;

    std::transform(lst.begin(), lst.end(), std::back_inserter(out), strToUpper);

    cbook_util::printContainer(out);

    std::cin.clear();

    std::cout << "Enter another series of strings: " << std::endl;
    std::list<std::string> lst2{++start, end};
    out.clear();

    std::transform(lst2.begin(), lst2.end(), std::back_inserter(out), strAppend);
    cbook_util::printContainer(out);
}
