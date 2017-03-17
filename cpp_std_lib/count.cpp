#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3, 4, 4, 3, 7, 8, 9, 10};

    // determine how many integers in a std::vector match a target value.
    int target1 = 3;
    int target2 = 5;
    long num_items1 = std::count(v.begin(), v.end(), target1);
    long num_items2 = std::count(v.begin(), v.end(), target2);
    std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
    std::cout << "number: " << target2 << " count: " << num_items2 << '\n';

    // use a lambda expression to count elements divisible by 3.
    long num_items3 = std::count_if(v.begin(), v.end(), [](int i) { return i % 3 == 0; });
    std::cout << "number divisible by three: " << num_items3 << '\n';
}