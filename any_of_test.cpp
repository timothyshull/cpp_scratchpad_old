#include <iostream>
#include <vector>

int in_range(int min, int max) {
    int range = abs(max - min);

    int real_min;
    if (min < max)
        real_min = min;
    else
        real_min = max;

    double adjusted = std::rand() * (static_cast<double>(range) / RAND_MAX) + real_min;
    return static_cast<int>(adjusted);
}

int main() {
    size_t vec_sz = 100;
    std::vector<int> tv;
    tv.reserve(vec_sz);

    for (unsigned long i = 0; i < vec_sz; ++i)
        tv.push_back(in_range(0, 100));

    std::cout << "printing initial\n";
    for (auto i : tv)
        std::cout << i << "\n";

    tv.erase(std::remove(tv.begin(), tv.end(), 12));
    std::cout << "printing erased all 12s\n";
    for (auto i : tv)
        std::cout << i << "\n";

    std::cout << "printing erased all evens\n";
    tv.erase(std::remove_if(tv.begin(), tv.end(), [](int x) { return x % 2 == 0; }));

    for (auto i : tv)
        std::cout << i << "\n";

    std::cout << std::any_of(tv.begin(), tv.end(), [](int x){return x == 12;}) << std::boolalpha << "\n";
    std::cout << std::any_of(tv.begin(), tv.end(), [](int x){return x == 28;}) << std::boolalpha << "\n";

    return 0;
}