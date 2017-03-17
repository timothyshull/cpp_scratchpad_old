#include <vector>
#include <unordered_map>
#include <iostream>

// use dynamic programming here
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {

        for (auto e : candidates) {
            _remainder = target;
            _counts.clear();
            for (auto f : candidates) { _counts[f] = 0; }
            for (auto f : candidates) { _marked[f] = false; }
            _combinationSum(candidates, e);
//            std::vector tmp;
//            int remainder{target};
//            while (remainder >= 0) {
//                remainder -= e;
//                tmp.push_back(e);
//            }
        }
        return _results;
    }

private:
    std::unordered_map<int, int> _marked;
    std::unordered_map<int, int> _counts;
    std::vector<std::vector<int>> _results;
    int _remainder;

    void _combinationSum(std::vector<int>& candidates, int current)
    {
        if (_remainder < 0) { return; }
        if (!_marked[current]) {
            _remainder -= current;
            ++_counts[current];
            _combinationSum(candidates, current);
        }
        _marked[current] = true;
        for (auto e : candidates) {
            if (e != current && !_marked[e]) {
                _combinationSum(candidates, e);
            }
        }
        _remainder += current;
        --_counts[current];
        if (_remainder == 0) {
            return _results.push_back(_counts_to_vector());
        }
    }

    std::vector<int> _counts_to_vector()
    {
        std::vector<int> r;
        for (auto e : _counts) {
            int tmp{e.second};
            while (tmp) {
                r.emplace_back(e.first);
                --tmp;
            }
        }
        return r;
    }
};

int main()
{
    std::vector<int> test1{2, 3, 6, 7};
    auto res = Solution{}.combinationSum(test1, 7);
    for (auto e : res) { for (auto f : e) { std::cout << f << "\n"; }}
    return 0;
}