//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_7_1_H
#define CPPCOOKBOOK_7_1_H

#include <algorithm>
#include <functional>

template<typename T, typename FwdIter>
FwdIter fixOutliersUBound(FwdIter p1, FwdIter p2, const T& oldVal, const T& newVal) {
    for (; p1 != p2; ++p1) {
        if (std::greater<T>()(*p1, oldVal)) {
            *p1 = newVal;
        }
    }
};

void useIterator();

#endif //CPPCOOKBOOK_7_1_H
