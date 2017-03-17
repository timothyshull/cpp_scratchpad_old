//
// Created by Timothy Shull on 12/18/15.
//

#include "3_1.h"
#include <iostream>

long hex2int(const std::string& hexStr) {
    char* offset;
    if (hexStr.length() > 2) {
        if (hexStr[0] == '0' && hexStr[1] == 'x') {
            return strtol(hexStr.c_str(), &offset, 0);
        }
        return strtol(hexStr.c_str(), &offset, 16);
    }
}