//
// Created by Timothy Shull on 12/31/15.
//

#include "10_2.h"
#include <iostream>
#include <iomanip>

void testFormatting() {
    std::ios_base::fmtflags flags = std::cout.flags();

    double pi = 3.14285714;

    std::cout << "pi = " << std::setprecision(5) << pi << '\n';

    std::cout << "pi = " << std::fixed << std::showpos << std::setprecision(3) << pi << '\n';

    std::cout << "pi = " << std::scientific << std::noshowpos << pi * 1000 << '\n';

    std::cout.flags(flags);
}
