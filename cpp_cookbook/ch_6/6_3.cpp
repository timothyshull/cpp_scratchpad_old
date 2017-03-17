//
// Created by Timothy Shull on 12/20/15.
//

#include "6_3.h"

void copyVector() {
    std::vector<std::string> vec{5};
    std::string foo[]{"my", "way", "or", "the", "highway"};

    vec.at(0) = "Today";
    vec.at(1) = "is";
    vec.at(2) = "a";
    vec.at(3) = "new";
    vec.at(4) = "day";

    // use the copy constructor to copy a vector
    std::vector<std::string> vec2{vec};
    vecPrint(vec2);

    vec.at(0) = "Tomorrow";

    // Use assign to copy a vector
    vec2.assign(vec.begin(), vec.end());
    vecPrint(vec2);

    vec2.assign(foo, foo + 5);
    vecPrint(vec2);

    std::vector<std::string>::iterator p;

    p = find(vec.begin(), vec.end(), "new");

    vec2.assign(vec.begin(), p);
    vecPrint(vec2);
}
