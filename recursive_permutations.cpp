#include <iostream>
#include <set>

void list_subsets(const std::set<int>& master);

void list_permutations(const std::string& str);

int main()
{
    list_subsets({1, 2, 3, 4});
    list_permutations("ibex");
    std::cout << "finished running !!!\n";
    return 0;
}

void list_subsets_r(const std::set<int> master, const std::set<int> used)
{
    if (master.empty()) {
        std::cout << "{";
        for (auto i : used) { std::cout << i << ", "; }
        std::cout << "}" << "\n";
        return;
    }

    list_subsets_r({++master.begin(), master.end()}, used);
    auto next_used = used;
    next_used.emplace(*master.begin());
    list_subsets_r({++master.begin(), master.end()}, next_used);
}

inline void list_subsets(const std::set<int>& master) { list_subsets_r(master, {}); }

void list_permutations_r(const std::string& str, const std::string& prev)
{
    if (str == "") {
        std::cout << prev << "\n";
        return;
    }
    for (std::size_t i{0}; i < str.size(); ++i) { list_permutations_r(str.substr(0, i) + str.substr(i + 1), prev + str[i]); }
}

inline void list_permutations(const std::string& str) { list_permutations_r(str, ""); }
