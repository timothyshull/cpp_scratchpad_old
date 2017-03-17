#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

class StockList {
public:
    static std::string stockSummary(std::vector<std::string>& lstOfArt, std::vector<std::string>& categories)
    {
        if (lstOfArt.empty() || categories.empty()) { return ""; }
        auto it1 = lstOfArt[0].begin();
        auto it2 = it1;
        for (; it1 != lstOfArt[0].end(); ++it1) { if (*it1 == ' ') { it2 = it1; }}
        auto num_len = it1 - it2;

        std::unordered_map<char, long> um(categories.size());
        for (auto s : categories) { um[s[0]] = 0; }

        for (auto s : lstOfArt) {
            if (std::any_of(categories.begin(), categories.end(), [&s](std::string& str) { return str[0] == s[0]; })) {
                it1 = s.end() - num_len;
                std::string count_str{it1, s.end()};
                std::stringstream ss;
                ss << count_str;
                long val;
                ss >> val;
                um[s[0]] += val;
            }
        }

        std::stringstream ss;
        for (auto s : categories) {
            ss << "(" << s << " : " << um[s[0]] << ")";
            if (s != *(categories.end() - 1)) { ss << " - "; }
        }
        return ss.str();
    }
};

int main()
{
    std::vector<std::string> art{"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> cd{"A", "B"};
    assert(StockList{}.stockSummary(art, cd) == "(A : 200) - (B : 1140)");
    art = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
    cd = {"A", "B", "C", "D"};
    assert(StockList{}.stockSummary(art, cd) == "(A : 0) - (B : 1290) - (C : 515) - (D : 600)");
    return 0;
}