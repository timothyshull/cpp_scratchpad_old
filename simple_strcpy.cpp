#include <iostream>

int main() {
    char str1[]{"test"};
    char str2[]{"tets"};

    for (int i = 0; i < 5; i++) {
        int tmp = (str1[i] = str2[i]);
        std::cout << "tmp: " << tmp << " for i: " << i << "\n";
    }
    std::cout << "str1: " << str1 << "\n";
    std::cout << "str2: " << str2 << "\n";
    return 0;
}