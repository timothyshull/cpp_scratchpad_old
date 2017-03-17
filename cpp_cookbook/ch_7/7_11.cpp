//
// Created by Timothy Shull on 12/20/15.
//

#include "7_11.h"
#include "util.h"
#include <list>


void printRangeToStream() {
    std::cout << "Enter a series of strings: " << std::endl;
    std::istream_iterator<std::string> start{std::cin};
    std::istream_iterator<std::string> end;
    std::vector<std::string> v{start, end};

    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, ", "));
}
