//
// Created by Timothy Shull on 12/21/15.
//

#include "4_2.h"
#include <iostream>

int power_recur(int a, int b) {
    if (a == 0 && b == 0)
        std::cout << "Undefined for input" << std::endl;
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    if (b > 0)

        return a * power_recur(a, b - 1);
}
