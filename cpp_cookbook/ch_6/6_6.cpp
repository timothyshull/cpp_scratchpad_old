//
// Created by Timothy Shull on 12/20/15.
//

#include "6_6.h"
#include <iostream>
#include <map>

void strMap() {
    std::map<std::string, std::string> strMap;

    strMap["Monday"] = "Montag";
    strMap["Tuesday"] = "Dienstag";
    strMap["Wednesday"] = "Mittwoch";
    strMap["Thursday"] = "Donnerstag";
    strMap["Friday"] = "Freitag";
    strMap["Saturday"] = "Samstag";
//    strMap.insert(std::make_pair("Sunday", "Sonntag"));
    strMap.insert(std::pair<std::string, std::string>("Sunday", "Sonntag"));

    for (std::map<std::string, std::string>::iterator p = strMap.begin(); p != strMap.end(); ++p) {
        std::cout << "English: " << p->first << ", German: " << p->second << std::endl;
    }

    std::cout << std::endl;

    strMap.erase(strMap.find("Tuesday"));

    for (std::map<std::string, std::string>::iterator p = strMap.begin(); p != strMap.end(); ++p) {
        std::cout << "English: " << p->first << ", German: " << p->second << std::endl;
    }

    // map prohibits duplicate keys, for duplicate keys use multimap
    // multimap does not provide [] access
}
