#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>

int main() {
    std::string s("hello");
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
    std::cout << s;
}