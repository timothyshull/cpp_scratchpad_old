#include <cassert>
#include <iostream>

int sequenceSum(int start, int end, int step)
{
    if (end < start) { return 0; }
    int a{start};
    start += step;
    while (start <= end) {
        a += start;
        start += step;
    }
    return a;
}

int main()
{

    //assert(sequenceSum(2, 6, 2) == 12);
    //assert(sequenceSum(1, 5, 1) == 15);
    assert(sequenceSum(1, 5, 3) == 5);
    assert(sequenceSum(0, 15, 3) == 45);
    assert(sequenceSum(16, 15, 3) == 0);
    assert(sequenceSum(2, 24, 22) == 26);
    assert(sequenceSum(2, 2, 2) == 2);
    assert(sequenceSum(2, 2, 1) == 2);
    assert(sequenceSum(1, 15, 3) == 35);
    assert(sequenceSum(15, 1, 3) == 0);

    return 0;
}