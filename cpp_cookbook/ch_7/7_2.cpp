//
// Created by Timothy Shull on 12/20/15.
//

#include "7_2.h"
#include "util.h"
#include <list>

void removeFromContainer() {
    std::list<std::string> lstStr;

    lstStr.push_back("On");
    lstStr.push_back("a");
    lstStr.push_back("cloudy");
    lstStr.push_back("cloudy");
    lstStr.push_back("day");

    std::list<std::string>::iterator p;

    p = find(lstStr.begin(), lstStr.end(), "day");
    lstStr.erase(p);

    lstStr.erase(remove(lstStr.begin(), lstStr.end(), "cloudy"), lstStr.end());
    cbook_util::printContainer(lstStr);
}
