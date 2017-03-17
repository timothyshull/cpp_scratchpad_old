//
// Created by Timothy Shull on 12/20/15.
//

#include "7_7.h"
#include "util.h"

void partitionRange() {
    std::cout << "Enter a series of strings: " << std::endl;
    std::istream_iterator<std::string> start{std::cin};
    std::istream_iterator<std::string> end;

    std::vector<std::string> v(start, end);

    std::vector<std::string>::iterator p = std::partition(v.begin(), v.end(), bind2nd(std::less<std::string>(), "foo"));

    cbook_util::printContainer(v);

    std::cout << "*p = " << *p << std::endl;
}
