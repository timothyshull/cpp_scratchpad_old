//
// Created by Timothy Shull on 12/23/15.
//

#include "7_12.h"
#include "util.h"

void myOwnPrintFunction() {
    std::cout << "Enter a series of strings: " << std::endl;
    std::istream_iterator<std::string> start{std::cin};
    std::istream_iterator<std::string> end;
    std::vector<std::string> v(start, end);

    cbook_util::printContainer(v);
    cbook_util::printRange(v.begin(), v.end(), ';', std::cout);
}
