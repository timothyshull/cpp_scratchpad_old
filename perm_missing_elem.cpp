//
// Created by Timothy Shull on 12/20/15.
//

#include "perm_missing_elem.h"


int perm_missing_elem(std::vector<int> &vec) {
    int xor_sum = 0;
    int length = static_cast<int>(vec.size());

    for (int i = 0; i < length; i++)
        xor_sum = xor_sum ^ vec[i] ^ (i + 1);

    return xor_sum ^ (length + 1);
}
