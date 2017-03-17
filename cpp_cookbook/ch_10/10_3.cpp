//
// Created by Timothy Shull on 12/31/15.
//

#include "10_3.h"
#include <iomanip>

void customStreamManip() {
    std::ios_base::fmtflags flags = std::cout.flags();

    double pi = 22.0 / 7.0;

    std::cout << "pi = " << std::scientific << pi * 1000 << '\n';
    std::cout << "pi = " << floatnormal << pi << '\n';

    std::cout.flags(flags);
}

void customStreamManip2() {
    std::cout << setFill('-') << setWidth(10) << std::right << "Proust\n";
}
