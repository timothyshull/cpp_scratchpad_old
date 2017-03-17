#include <iostream>
#include <vector>

// #include "find_failed_build.h"

int main()
{
//    long test_1[2] = {0, 1};
//    long test_2[3] = {0, 1, 2};
//    long test_3[4] = {0, 1, 2, 3};
//    long test_4[5] = {0, 1, 2, 3, 4};
//    long test_5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//
//    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7};
//    std::find_if(v.begin(), v.end(), [&test_1](int i) {
//        return i % 2 == 0;
//    });
//
//    std::cout << "Hello, World!" << std::endl;
    std::vector<int> a(10);
    int count{25};

    for (int i{0}; i < a.size(); ++i) {
        a[i] = count++;
    }

    for (auto j : a) {
        std::cout << j << "\n";
    }

    std::cout << "\n\n";
    std::vector<int> b(10);
    count = 45;

    for (int i{0}; i < b.size(); ++i) {
        b[i] = ++count;
    }

    for (auto j : b) {
        std::cout << j << "\n";
    }
    return 0;
}