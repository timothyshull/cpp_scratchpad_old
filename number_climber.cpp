#include <vector>
#include <cmath>
#include <cassert>
#include <stack>

bool climb(std::vector<int>& v, int current, int n)
{
    if (current > n) { return false; }
    if (current == n) {
        v.emplace_back(current);
        return true;
    }

    bool l{climb(v, current * 2, n)};
    bool r{climb(v, (current * 2) + 1, n)};

    if (l || r) {
        v.emplace_back(current);
        return true;
    }
    return false;
}

std::vector<int> climb(int n)
{
    std::vector<int> path;
    climb(path, 1, n);
    return {path.rbegin(), path.rend()};
}

std::vector<int> climb_iterative(int n)
{
    std::vector<int> path;
    while (n > 1) {
        path.insert(path.begin(), n);
        n /= 2;
    }
    path.insert(path.begin(), n);
    return path;
}

int main()
{
    std::vector<int> expected{1};
    std::vector<int> actual{climb(1)};
    assert(actual == expected);

    expected = {1, 2, 5, 10};
    actual = climb(10);
    assert(actual == expected);

    expected = {1, 3, 6, 13};
    actual = climb(13);
    assert(actual == expected);

    return 0;
}