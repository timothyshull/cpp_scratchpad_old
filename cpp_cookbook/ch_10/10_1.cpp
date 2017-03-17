//
// Created by Timothy Shull on 12/25/15.
//

#include "10_1.h"
#include <iostream>
#include <iomanip>

void alignedText() {
    std::ios_base::fmtflags flags = std::cout.flags();
    std::string first, last, cityState;
    int width{20};

    first = "Richard";
    last = "Stevens";
    cityState = "Tucson, AZ";

    std::cout << std::left
    << std::setw(width) << first
    << std::setw(width) << last
    << std::setw(width) << cityState << std::endl;

    std::cout.flags(flags);
}
