//
// Created by Timothy Shull on 12/20/15.
//

#include "7_3.h"
#include "util.h"

void randomShuffle() {
    std::vector<int> v;
    std::back_insert_iterator<std::vector<int>> p{std::back_inserter(v)};

    for (int i = 0; i < 10; ++i)
        *p = i;

    cbook_util::printContainer(v, true);

    std::random_shuffle(v.begin(), v.end());

    cbook_util::printContainer(v, true);
}
