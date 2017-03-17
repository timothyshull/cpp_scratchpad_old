#include <vector>
#include <cassert>

std::vector<long> numbersWithDigitInside(long x, long d)
{
    long count{0};
    long sum{0};
    long product{1};

    for (long i{1}; i <= x; ++i) {
        long tmp{i};
        while (tmp) {
            if (tmp % 10 == d) {
                ++count;
                sum += i;
                product *= i;
                break;
            }
            tmp /= 10;
        }
    }

    return {count, sum, product == 1 ? 0 : product};
}

int main()
{
    std::vector<long> expected{0, 0, 0};
    std::vector<long> actual{numbersWithDigitInside(5, 6)};
    assert(actual == expected);
    
    expected = {1, 6, 6};
    actual = numbersWithDigitInside(7, 6);
    assert(actual == expected);

    expected = {3, 22, 110};
    actual = numbersWithDigitInside(11, 1);
    assert(actual == expected);

    expected = {2, 30, 200};
    actual = numbersWithDigitInside(20, 0);
    assert(actual == expected);

    expected = {9, 286, 5955146588160};
    actual = numbersWithDigitInside(44, 4);
    assert(actual == expected);
    return 0;
}