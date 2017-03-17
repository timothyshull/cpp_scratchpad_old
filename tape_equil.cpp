//
// Created by Timothy Shull on 12/20/15.
//

#include "tape_equil.h"
#include <cstdlib>
#include <iostream>

int tape_equilibrium(const std::vector<int> &vec) {
    int min, top, bottom;
    top = 0;

    std::for_each(vec.begin() + 1, vec.end(), [&](int n) {
        top += n;
    });

    bottom = vec[0];
    min = abs(bottom - top);

    for (std::vector<int>::const_iterator p = vec.begin() + 1; p != vec.end() - 1; ++p) {
        bottom += *p;
        top -= *p;
        if (abs(bottom - top) < min) {
            min = abs(bottom - top);
        }
    }
    return min;
}
