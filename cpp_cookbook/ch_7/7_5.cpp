//
// Created by Timothy Shull on 12/20/15.
//

#include "7_5.h"
#include "util.h"
#include <list>

void sequenceMerge() {
    std::vector<std::string> v1, v2, v3;

    v1.push_back("a");
    v1.push_back("b");
    v1.push_back("e");

    v2.push_back("b");
    v2.push_back("d");
    v2.push_back("f");

    v3.reserve(v1.size() + v2.size() + 1);

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter<std::vector<std::string>>(v3));

    cbook_util::printContainer(v3);

    std::random_shuffle(v3.begin(), v3.end());
    std::sort(v3.begin(), v3.begin() + v3.size() / 2);
    std::sort(v3.begin() + v3.size() / 2, v3.end());

    cbook_util::printContainer(v3);

    std::inplace_merge(v3.begin(), v3.begin() + 3, v3.end());

    cbook_util::printContainer(v3);

    std::list<std::string> lstStr1, lstStr2;

    lstStr1.push_back("Frank");
    lstStr1.push_back("Rizzo");
    lstStr1.push_back("Bill");
    lstStr1.push_back("Cheetoh");

    lstStr2.push_back("Allie");
    lstStr2.push_back("McBeal");
    lstStr2.push_back("Slick");
    lstStr2.push_back("Willie");

    lstStr1.sort();
    lstStr2.sort();

    lstStr1.merge(lstStr2);

    cbook_util::printContainer(lstStr1);
}
