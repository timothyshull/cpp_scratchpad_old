//
// Created by Timothy Shull on 12/19/15.
//

#include "3_6.h"
#include <cmath>

bool doubleEquals(double d, double d1, double epsilon) {
    return fabs(d - d1) < epsilon;
}

bool doubleLess(double d, double d1, double epsilon, bool b = false) {
    if (fabs(d - d1) < epsilon) {
        return b;
    }
    return d < d1;
}

bool doubleGreater(double d, double d1, double epsilon, bool b = false) {
    if (fabs(d - d1) < epsilon) {
        return b;
    }
    return d > d1;
}
