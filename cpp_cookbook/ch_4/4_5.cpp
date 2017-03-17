//
// Created by Timothy Shull on 12/19/15.
//

#include "4_5.h"
#include <iostream>
#include <boost/algorithm/string.hpp>


void str_trim_examples() {
    std::string s1 = "        leading spaces";

    boost::trim_left(s1);
    std::string s2 = boost::trim_left_copy(s1);

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;

    s1 = "YYYYtestXXXXXX";
    s2 = boost::trim_copy_if(s1, boost::is_any_of("XY"));
    boost::trim_if(s1, boost::is_any_of("XY"));

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;

    s1 = "1234 numbers 9876";
    s2 = boost::trim_copy_if(s1, boost::is_digit());

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;

    s1 = " *****trim*******     ";
    s2 = boost::trim_copy_if(boost::trim_copy(s1), boost::is_any_of("*"));

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
}
