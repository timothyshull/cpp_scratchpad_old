#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    std::system("ls -l >test.txt"); // execute the UNIX command "ls -l >test.txt"
    std::cout << std::ifstream("test.txt").rdbuf();
}