//
// Created by Timothy Shull on 12/19/15.
//

#include "3_3.h"
#include <iomanip>
#include <sstream>

std::string ss_int2hex(int i) {
    std::stringstream ss;
    ss << std::showbase << std::hex << i;
    return ss.str();
}