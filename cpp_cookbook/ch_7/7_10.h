//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_7_10_H
#define CPPCOOKBOOK_7_10_H

template<typename In, typename Out, typename UnPred>
Out copyIf(In first, In last, Out result, UnPred pred) {
    for (; first != last; ++first)
        if (pred(*first))
            *result++ = *first;
    return result;
};

void myOwnAlgorithm();

#endif //CPPCOOKBOOK_7_10_H
