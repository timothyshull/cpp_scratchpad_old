#include <iostream>
#include <fstream>

// demonstrates a temporary stream for rvalue and move semantics

int main() {
    std::string s{"hello"};
    std::ofstream("fstream2.tmp") << s << std::endl;

    std::ofstream("fstream2.tmp", std::ios::app) << "world" << std::endl;
}