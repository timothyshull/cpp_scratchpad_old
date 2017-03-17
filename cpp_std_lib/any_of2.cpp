#include <vector>
#include <numeric>
#include <iostream>
#include <unordered_set>

struct Evenly_multiplies_to {
    const int multiplier;
    const int target;

    Evenly_multiplies_to(int mult, int target) : multiplier{mult}, target{target} {}

    bool operator()(int n) const { return n * multiplier == target; }
};

int main()
{
    std::unordered_set<int> us1{2, 6, 10, 11, 12, 13, 45, 96};

    if (std::any_of(us1.cbegin(), us1.cend(), Evenly_multiplies_to{7, 84})) {
        std::cout << "At least one number results in 84 when multiplied by 7\n";
    }

    return 0;
}