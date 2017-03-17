//
// Created by Timothy Shull on 12/19/15.
//

#include "6_1.h"
#include <iostream>
#include <vector>

void demoVector() {
    std::vector<int> intVec;
    std::vector<std::string> strVec;

    intVec.push_back(3);
    intVec.push_back(9);
    intVec.push_back(6);

    std::string s = "Army";
    strVec.push_back(s);
    s = "Navy";
    strVec.push_back(s);
    s = "Air Force";
    strVec.push_back(s);

    for (std::vector<std::string>::size_type i = 0; i < intVec.size(); ++i)
        std::cout << "intVec[" << i << "] = " << intVec.at(i) << std::endl;

    for (std::vector<std::string>::iterator p = strVec.begin(); p != strVec.end(); ++p)
        std::cout << *p << std::endl;

    // original code used [] above - added this for safety
    try {
        intVec.at(300) = 2;
    } catch (std::out_of_range& e) {
        std::cerr << "out_of_range: " << e.what() << std::endl;
    }

    // inserting
    s = "Marines";
    // Tries to find the element, but cannot so p is equal to the end element
    std::vector<std::string>::iterator p = find(strVec.begin(), strVec.end(), s);
    if (p == strVec.end())
        strVec.insert(p, s);

    for (p = strVec.begin(); p != strVec.end(); ++p)
        std::cout << *p << std::endl;

    // Assign allows you to insert a range or many copies of a value
    std::string sarr[3] = {"Ernie", "Bert", "Elmo"};
    std::string s2 = "Oscar";
    strVec.assign(sarr, sarr + 3);
    strVec.assign(50, s2);

    std::cout << (sizeof(sarr) / sizeof(*sarr)) << std::endl;

    for (p = strVec.begin(); p != strVec.end(); ++p)
        std::cout << *p << std::endl;

    /*std::vector<std::string> strVec2 {sarr, sarr + 3};

    for (p = strVec2.begin(); p != strVec2.end(); ++p)
        std::cout<< *p << std::endl;*/

    std::vector<std::string> strVec2;

    strVec2.assign(sarr, sarr + 3);

    for (p = strVec2.begin(); p != strVec2.end(); ++p)
        std::cout << *p << std::endl;
}
