#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target)
    {
        int pivot{0};
        auto l = 0;
        auto h = nums.size() - 1;

        while (l <= h) {
            auto m = (l + h) / 2;
            if (nums[m] == target) { return m; }
            if (nums[m] < nums[h]) { 
                if (nums[m] < target && target < nums[h]) { l = m + 1; }
            }
            else if (nums[m] < nums[h] && (nums[m] < target && target < nums[h])) { l = m + 1; }
            else if (nums[h] < nums[m]) { l = m + 1; }
        }
    
    }
};
