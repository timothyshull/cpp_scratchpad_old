#include<string>
#include<iostream>
#include"utility.h"

int main() {
    std::string s{"zoo"};

    rtrim(s, 'o');
    std::cout << s << "\n";

    return 0;
}
