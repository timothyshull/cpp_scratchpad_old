#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cassert>

class RevRot {
public:
    static std::string revRot(const std::string& strng, unsigned int sz)
    {
        if (sz == 0 || !(strng.size() / sz)) { return ""; }

        std::stringstream ss;

        std::string::const_iterator s_beg{strng.cbegin()};
        std::string::const_iterator s_end{s_beg + sz};
        while (s_end <= strng.cend()) {
            std::string t{s_beg, s_end};
            int sum{0};
            for (auto c : t) { sum += std::pow(static_cast<int>(c - '0'), 3); }

            if (sum % 2 == 0) {
                ss << std::string{t.rbegin(), t.rend()};
            } else {
                std::rotate(t.begin(), t.begin() + 1, t.end());
                ss << t;
            }
            s_beg = s_end;
            s_end = s_beg + sz;
        }

        return ss.str();
    }
};

int main()
{
    std::string s = "1234";
    unsigned int sz{0};
    assert(RevRot::revRot(s, sz) == "");
    s = "";
    assert(RevRot::revRot(s, sz) == "");
    s = "733049910872815764";
    sz = 5;
    assert(RevRot::revRot(s, sz) == "330479108928157");
    s = "73304991087281576455176044327690580265896";
    sz = 8;
    assert(RevRot::revRot(s, sz) == "1994033775182780067155464327690480265895");
    return 0;
}

// NOTES:
// needed to check sz == 0 before strng.size() / sz
// the end iterator iterated past the end, needed to check <=
// needed to move modification of s_beg and s_end to end of while loop
// needed to learn the proper way to call rotate