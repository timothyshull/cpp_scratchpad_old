#include <cassert>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) { return true; }
        x = x > 0 ? x : -x;
        while (x) {
            if (x / static_cast<int>(std::pow(10, std::floor(std::log10(x)))) != x % 10) { return false; }
            else {
                x -= static_cast<int>(std::pow(10, std::floor(std::log10(x)))) * (x / static_cast<int>(std::pow(10, std::floor(std::log10(x)))));
                x /= 10;
            }
        }
        return true;
    }
};

int main() {
    assert(Solution{}.isPalindrome(1));
    assert(Solution{}.isPalindrome(121));
    assert(!Solution{}.isPalindrome(122));
    assert(Solution{}.isPalindrome(1223221));
    assert(Solution{}.isPalindrome(-444));
    assert(Solution{}.isPalindrome(98766789));
    assert(!Solution{}.isPalindrome(98765789));
    return 0;
}