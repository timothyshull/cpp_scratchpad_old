#include <iostream>
#include <vector>
#include <cassert>

// counting sort
template<typename Item_type>
int max_contiguous_difference(std::vector<Item_type>& coll)
{
    if (coll.size() <= 1) { return -1; }

    auto result = std::minmax_element(coll.begin(), coll.end());
    Item_type min{*result.first};
    Item_type max{*result.second};

    std::vector<int> counts(static_cast<std::vector<int>::size_type>(max - min + 1), 0);
    for (auto e : coll) { ++counts[e - min]; }
    for (auto it = counts.begin() + 1; it != counts.end(); ++it) { *it = *it + *(it - 1); }

    std::vector<Item_type> aux(coll.size());
    for (auto it = coll.begin(); it != coll.end(); ++it) { aux[--counts[*it - min]] = *it; }

    int max_diff{0};
    for (auto it = aux.begin() + 1; it != aux.end(); ++it) {
        int t{*it - *(it - 1)};
        if (max_diff < t) { max_diff = t; }
    }
    return max_diff;
}

int main()
{
    std::vector<int> a{5, 4, 1, 2, 3};
    std::vector<int> b{7, 4, 1, 1, 2, 3};
    std::vector<int> c{0, 2, 4, 6, 8};
    std::vector<int> d{1};
    std::vector<int> e{11, 21, 1, 84, 32, 9, 9, 4};

    assert(max_contiguous_difference(a) == 1);
    assert(max_contiguous_difference(b) == 3);
    assert(max_contiguous_difference(c) == 2);
    assert(max_contiguous_difference(d) == -1);
    assert(max_contiguous_difference(e) == 52);
    return 0;
}