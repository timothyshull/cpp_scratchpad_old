#include <vector>
#include <iostream>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        int idx1{};
        int idx2{};
        for (int i{0}; i < nums.size(); ++i) {
            for (int j{0}; j < nums.size(); ++j) {
                if (j != i && nums[i] + nums[j] == target) {
                    idx1 = i;
                    idx2 = j;
                    break;
                }
            }
        }
        return {idx1, idx2};
    }
};

// two pass hash table -> goes from O(n) to O(1)
std::vector<int> twoSum(std::vector<int> nums, int target)
{
    std::map<int, int> map;
    for (int i{0}; i < nums.size(); ++i) { map.emplace(nums[i], i); }
    int complement;
    for (int i{0}; i < nums.size(); ++i) {
        complement = target - nums[i];
        if (map.find(complement) != map.end() && map[complement] != i) {
            return {i, map[complement]};
        }
    }
    throw std::out_of_range{"No two sum solution"};
}

// one pass hash
std::vector<int> twoSumOnePass(std::vector<int> nums, int target)
{
    std::map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        int complement{target - nums[i]};
        if (map.find(complement) != map.end()) { return {map[complement], i}; }
        map[nums[i]] = i;
    }
    throw std::out_of_range{"No two sum solution"};
}



int main()
{
    std::vector<int> test1{2, 7, 11, 15};
    for (auto i : Solution{}.twoSum(test1, 9)) { std::cout << i << " "; }

    for (auto i : twoSum(test1, 9)) { std::cout << i << " "; }
    for (auto i : twoSumOnePass(test1, 9)) { std::cout << i << " "; }
    return 0;
}

