//
// Created by Timothy Shull on 12/20/15.
//

#include "frog_jump.h"

int frog_jump(int X, int Y, int D) {
    int dist = Y - X;
    if (dist % D == 0)
        return dist / D;

    return dist / D + 1;
}
