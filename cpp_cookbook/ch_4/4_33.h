//
// Created by Timothy Shull on 12/19/15.
//

#ifndef CPPCOOKBOOK_4_33_H
#define CPPCOOKBOOK_4_33_H

#include <iostream>
#include <string>
#include <boost/regex.hpp>

void printRegexTokens(const std::string& str, const std::string& reStr) {
    boost::regex re(reStr);
    boost::sregex_token_iterator p(str.begin(), str.end(), re, -1);
    boost::sregex_token_iterator end;

    while (p != end)
        std::cout << *p++ << std::endl;
}

#endif //CPPCOOKBOOK_4_33_H
