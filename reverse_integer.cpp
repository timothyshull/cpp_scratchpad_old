#include <vector>
#include <iostream>

class Solution {
public:
    int reverse(int x)
    {
        std::vector<int> rev;
        bool is_pos{x > 0};
        x = is_pos ? x : -x;
        // modulo will create negative numbers for each
        while (x) {
            rev.emplace_back(x % 10);
            x /= 10;
        }
        long res{0};
        long mult{1};
        for (auto i : rev) {
            res += mult * i;
            mult *= 10;
        }
        if (is_pos) { return res <= std::numeric_limits<int>::max() ? static_cast<int>(res) : 0; }
        else { return -res >= std::numeric_limits<int>::min() ? static_cast<int>(-res) : 0; }
    }
};


int main() {
    std::cout << Solution{}.reverse(123) << "\n";
    std::cout << Solution{}.reverse(321) << "\n";
    int res1{Solution{}.reverse(-123)};
    int res2{Solution{}.reverse(-321)};
    return 0;
}