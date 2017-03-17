//
// Created by Timothy Shull on 12/20/15.
//

#include "7_4.h"
#include "util.h"


void comparingRanges() {
    std::vector<std::string> vec1, vec2;

    vec1.push_back("Charles");
    vec1.push_back("in");
    vec1.push_back("Charge");

    vec2.push_back("Charles");
    vec2.push_back("in");
    vec2.push_back("charge");

    if (std::equal(vec1.begin(), vec1.end(), vec2.begin())) {
        std::cout << "The two ranges are equal" << std::endl;
    } else {
        std::cout << "The two ranges are not equal" << std::endl;
    }

    std::string s1 = "abcde";
    std::string s2 = "abcdf";
    std::string s3 = "abc";

    std::cout << std::boolalpha << std::lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end()) <<
    std::endl;
    std::cout << std::boolalpha << std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) <<
    std::endl;
    std::cout << std::boolalpha << std::lexicographical_compare(s1.begin(), s1.end(), s3.begin(), s3.end()) <<
    std::endl;
    std::cout << std::boolalpha << std::lexicographical_compare(s3.begin(), s3.end(), s1.begin(), s1.end()) <<
    std::endl;

    std::pair<std::string::iterator, std::string::iterator> iters = std::mismatch(s1.begin(), s1.end(), s2.begin());

    std::cout << "first mismatch = " << *(iters.first) << std::endl;
    std::cout << "second mismatch = " << *(iters.second) << std::endl;
}
