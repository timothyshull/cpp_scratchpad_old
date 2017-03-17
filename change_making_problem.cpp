#include <vector>
#include <algorithm>

// see https://en.wikipedia.org/wiki/Coin_problem
// see https://en.wikipedia.org/wiki/Change-making_problem
// all related to the knapsack problem -> https://en.wikipedia.org/wiki/Knapsack_problem
// https://en.wikipedia.org/wiki/List_of_knapsack_problems

std::vector<std::vector<int>> generate_change_matrix(std::vector<int>& coins, std::size_t r)
{
    std::vector<std::vector<int>> ret(coins.size() + 1, std::vector<int>(r + 1, 0));
    for (int i{0}; i < r + 1; ++i) { ret[0][i] = i; }
    return ret;
}

int make_change(std::vector<int>& coins, int target)
{
    auto m = generate_change_matrix(coins, target);
    for (int c{1}; c < coins.size() + 1; ++c) {
        for (int r{1}; r < target + 1; ++ r) {
            if (coins[c - 1] == r) { m[c][r] = 1; }
            else if (coins[c - 1] > r) { m[c][r] = m[c - 1][r]; }
            else { m[c][r] = std::min(m[c - 1][r], 1 + m[c][r - coins[c - 1]]); }
        }
    }
    return m[m.size() - 1][m[0].size() - 1];
}