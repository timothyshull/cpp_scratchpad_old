//
// Created by Timothy Shull on 12/20/15.
//

#include "6_5.h"
#include <list>

void storeList() {
    printer<std::string> strPrinter;
    printer<int> intPrinter;

    std::list<std::string> lstOne;
    std::list<std::string> lstTwo;

    lstOne.push_back("red");
    lstOne.push_back("green");
    lstOne.push_back("blue");

    lstTwo.push_back("orange");
    lstTwo.push_back("yellow");
    lstTwo.push_back("fuschia");

    std::for_each(lstOne.begin(), lstOne.end(), strPrinter);

    lstOne.sort();
    lstTwo.sort();

    lstOne.merge(lstTwo);

    std::for_each(lstOne.begin(), lstOne.end(), strPrinter);

    std::list<int> intLst;

    intLst.push_back(0);
    intLst.push_back(1);
    intLst.push_back(2);
    intLst.push_back(3);
    intLst.push_back(4);
    intLst.push_back(5);

    intLst.remove_if(std::bind2nd(std::greater<int>(), 2));

    std::for_each(intLst.begin(), intLst.end(), intPrinter);

    intLst.remove_if(even);

    // Adding and removing elements from a list takes constant time
    // Adding and removing elements from a vector takes amortized constant time, i.e.
    // it occasionally needs to resize its buffer and this operation gets averaged over all of the constant time operations

    // insert
    std::list<std::string> strList2;
    std::list<std::string>::iterator p;

    std::string s = "Scion";

    p = std::find(strList2.begin(), strList2.end(), "Toyota");

    strList2.insert(p, s);
    strList2.insert(p, 16, s);
    strList2.insert(p, lstTwo.begin(), lstTwo.end());

    // erase
    strList2.erase(p);
    strList2.erase(p, strList2.end());
    strList2.clear();
}
