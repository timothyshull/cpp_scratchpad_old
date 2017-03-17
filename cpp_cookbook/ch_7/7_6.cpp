//
// Created by Timothy Shull on 12/20/15.
//

#include "7_6.h"
#include "util.h"
#include <list>

void sortRange() {
    std::cout << "Enter a series of strings: " << std::endl;
    std::istream_iterator<std::string> start{std::cin};
    std::istream_iterator<std::string> end;
    std::vector<std::string> v(start, end);
    std::sort(v.begin(), v.end());
    cbook_util::printContainer(v);

    std::random_shuffle(v.begin(), v.end());

    std::string* arr = new std::string[v.size()];

    std::sort(&arr[0], &arr[v.size()]);
    cbook_util::printRange(&arr[0], &arr[v.size()]);

    std::list<std::string> lst(v.begin(), v.end());

    lst.sort();

    cbook_util::printContainer(lst);
}
