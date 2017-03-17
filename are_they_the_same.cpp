#include <vector>
#include <cassert>

class Same {
public:
    static bool comp(std::vector<int> a, std::vector<int> b) {
        if (a.size() == 0 && b.size() == 0) { return true; }
        if (a.size() != b.size()) { return false; }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for (auto it1 = a.begin(), it2 = b.begin(); it1 != a.end(), it2 != b.end(); ++it1, (void) ++it2) {
            if (*it2 != *it1 * *it1) { return false; }
        }
        return true;
    }
};


int main()
{
    std::vector<int> a1{121, 144, 19, 161, 19, 144, 19, 11};
    std::vector<int> b2{11 * 11, 121 * 121, 144 * 144, 19 * 19, 161 * 161, 19 * 19, 144 * 144, 19 * 19};
    bool r{Same::comp(a1, b2)};
    assert(r);
    return 0;
}