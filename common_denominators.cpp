#include <string>
#include <vector>
#include <cassert>

class Fracts {
public:
    using ull = unsigned long long;

    static std::string convertFrac(std::vector<std::vector<unsigned long long>>& lst)
    {
        ull l{1};
        for (const auto& e : lst) { l = lcm(l, e[1]); }
        std::string r{""};
        for (const auto& e : lst) { r += "(" + std::to_string(e[0] * (l / e[1])) + "," + std::to_string(l) + ")"; }
        return r;
    }

    static ull gcd(ull m, ull n)
    {
        if (n == 0) { return m; }
        return gcd(n, m % n);
    }

    inline static ull lcm(ull m, ull n) { return (m * n) / gcd(m, n); }
};

int main()
{
    std::vector<std::vector<unsigned long long>> r1{
            {1, 2},
            {1, 3},
            {1, 4}
    };
    std::string ans1 = Fracts::convertFrac(r1);
    std::string sol1 = "(6,12)(4,12)(3,12)";
    assert(sol1 == ans1);
    return 0;
}
