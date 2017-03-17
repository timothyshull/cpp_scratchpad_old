//
// Created by Timothy Shull on 12/21/15.
//

#include "4_1.h"
#include <iostream>

int factorial_n_recur(int n) {
    if (n < 1)
        std::cout << "Invalid input" << std::endl;
    if (n == 1)
        return 1;
    return n * factorial_n_recur(n - 1);
}
