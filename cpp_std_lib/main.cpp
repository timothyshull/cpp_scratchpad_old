#include <iostream>
#include <array>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    std::array<int, 5> test_arr{3, 6, 8, 4, 5};
    for (auto i : test_arr) {
        std::cout << i << std::endl;
    }

    for (auto it = test_arr.begin(); it != test_arr.end(); ++it) {
        std::cout << *it << std::endl;
        *it = dis(gen);
    }

    for (auto it = test_arr.crbegin(); it != test_arr.crend(); ++it) {
        std::cout << *it << std::endl;
    }

    test_arr.fill(0);
    for (auto i : test_arr) {
        std::cout << i << std::endl;
    }

    std::array<char, 20> char_arr;
    strcpy(char_arr.data(), "c strings as arrays");
    printf("%s\n", char_arr.data());


    std::vector<int> test_vec{43, 54, 103, 45, 907};

    struct TestInMain {
        void operator()(int &in) { in *= 12; };
    };

    std::for_each(test_vec.begin(), test_vec.end(), TestInMain());

    for (auto i : test_vec) {
        std::cout << i << std::endl;
    }

    std::for_each(test_vec.begin(), test_vec.end(), [](int &in) { in /= 12; });

    for (auto i : test_vec) {
        std::cout << i << std::endl;
    }

    test_vec.resize(100);

    for (auto i : test_vec) {
        std::cout << i << std::endl;
    }

    std::for_each(test_vec.begin(), test_vec.end(), [&dis, &gen](int &in) { in = dis(gen); });

    for (auto i : test_vec) {
        std::cout << i << std::endl;
    }

    return 0;
}