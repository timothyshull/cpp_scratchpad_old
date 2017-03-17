#include <string>
#include <iostream>

std::size_t fact(std::size_t n) { return (n == 1) ? 1 : n * fact(n - 1); }

// TODO: a bubble sort style iteration with swaps might be more simple
void print_permutations(std::string&& s)
{
    auto n = s.size();
    auto f = fact(n);
    int j{1};
    int m{0};

    for (int c{0}; c < f;) {
        std::string perm{s};

        int k{0};
        while (k != f / n) {
            while (j != n - 1) {
                std::cout << perm << "\n";
                std::swap(perm[j], perm[j + 1]);
                ++k;
                ++c;
                ++j;
            }
            j = 1;
        }
        ++m;

        if (m == n) { break; }
        std::swap(s[0], s[m]);
    }
}

int main()
{
    print_permutations("ABCDEFG");
    return 0;
}