//
// Created by Timothy Shull on 12/20/15.
//

#include "7_1.h"
#include <iostream>
#include <list>

static const int ARRAY_SIZE = 5;

void useIterator() {
    std::list<std::string> lstStr;

    lstStr.push_back("Please");
    lstStr.push_back("leave");
    lstStr.push_back("a");
    lstStr.push_back("message");

    for (std::list<std::string>::iterator p = lstStr.begin(); p != lstStr.end(); ++p)
        std::cout << *p << std::endl;

    for (std::list<std::string>::reverse_iterator p = lstStr.rbegin(); p != lstStr.rend(); ++p)
        std::cout << *p << std::endl;

    std::string arrStr[ARRAY_SIZE]{"my", "cup", "cup", "runneth", "over"};

    for (std::string* p = &arrStr[0]; p != &arrStr[ARRAY_SIZE]; ++p)
        std::cout << *p << std::endl;

    std::list<std::string> lstStrDest;
    std::unique_copy(&arrStr[0], &arrStr[ARRAY_SIZE], std::back_inserter(lstStrDest));

}
