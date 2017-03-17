//
// Created by Tim Shull on 10/23/16.
//

#include <iostream>
#include <fstream>
#include <sstream>

void first_word(const std::string &line) {
    std::stringstream ss{line};
    std::string first;
    std::getline(ss, first, ' ');
    if (!first.empty()) {
        std::cout << first << "\n";
    }
}

void scanner(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
        first_word(line);
    }
}

int main(int argc, char *argv[]) {
    std::ifstream in{argv[1]};
    scanner(in);
    return 0;
}
