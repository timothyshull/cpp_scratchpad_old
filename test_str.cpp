#include <iostream>

int main() {
    const char test_arr[]{"test"};
    std::string test_str{"test"};
    std::cout << "sizeof test_arr: " << sizeof test_arr << "\n";
    std::cout << "strlen(test_arr): " << strlen(test_arr) << "\n";
    std::cout << "test_str.size(): " << test_str.size() << "\n";
    std::cout << "test_str.capacity(): " << test_str.capacity() << "\n";

    std::string test_str2;
    test_str2.reserve(1024);
    std::cout << "test_str2.capacity(): " << test_str2.capacity() << "\n";
//    std::cout << "test_str.size(): " << test_str.size();
    return 0;
}