//
// Created by Tim Shull on 10/30/16.
//

#include<array>
#include<iostream>

int main() {
    std::array<int, 5> test{1, 2, 3, 4, 5};
    std::array<int, 0> test2{};
    std::cout << std::boolalpha << "test.empty() returns " << test.empty() << "\n";
    std::cout << std::boolalpha << "test2.empty() returns " << test2.empty() << "\n";
    std::cout << "test.size() returns " << test.size() << "\n";
    std::cout << "test2.size() returns " << test2.size() << "\n";
    std::cout << "test.max_size() returns " << test.max_size() << "\n";
    std::cout << "test2.max_size() returns " << test2.max_size() << "\n";

    std::array<int, 5>::value_type test_val{};
    std::cout << "typeid().name() of std::array<int, 5>::value_type returns " << typeid(test_val).name() << "\n";

    std::array<int, 5>::size_type test_val2{};
    std::cout << "typeid().name() of std::array<int, 5>::size_type returns " << typeid(test_val2).name() << "\n";

    return 0;
}