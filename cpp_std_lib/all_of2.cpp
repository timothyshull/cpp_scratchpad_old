#include <vector>
#include <numeric>
#include <iostream>
#include <map>

//template< class InputIt, class UnaryPredicate >
//bool all_of( InputIt first, InputIt last, UnaryPredicate p );
//(1) (since C++11)

struct Divisible_by {
    const int divisor;

    Divisible_by(int n) : divisor{n} {}

    bool operator()(int n) const { return n % divisor == 0; }
};

int main()
{
    std::vector<float> v1{.4567, 32.3432, 76.594, 1209.567};

    if (std::all_of(v1.cbegin(), v1.cend(), [](int i) { return i % 2 == 0; })) { std::cout << "All numbers are even\n"; }

    std::map<std::string, int> m1{
            {"one", 1},
            {"two", 2},
            {"three", 3},
            {"four", 4},
            {"five", 5},
            {"six", 6},
    };

    if (std::all_of(m1.cbegin(), m1.cend(), [](std::pair<std::string, int> p) {
        std::cout << p.first << "\n";
        std::cout << p.second << "\n";
        return p.first != "zero" && p.second != 0;
    })) { std::cout << "All keys are not \'zero\' and all values are greater than 0\n"; }

    return 0;
}