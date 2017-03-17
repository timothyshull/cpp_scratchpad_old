//
// Created by Timothy Shull on 12/20/15.
//

#include "7_10.h"
#include "util.h"
#include <list>

void myOwnAlgorithm() {
    std::cout << "Enter a series of strings: " << std::endl;
    std::istream_iterator<std::string> start{std::cin};
    std::istream_iterator<std::string> end;
    std::vector<std::string> v{start, end};

    std::list<std::string> lst;

    copyIf(v.begin(), v.end(), std::back_inserter<std::list<std::string>>(lst),
           bind2nd(std::less<std::string>(), "cookie"));

    cbook_util::printContainer(lst);
}
