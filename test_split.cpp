//
// Created by Tim Shull on 10/23/16.
//

#include <iostream>
#include <fstream>
#include "util.h"

int main(int argc, char *argv[]) {
    std::ifstream in{argv[1]};
    std::string line;
    std::getline(in, line);
    std::vector<std::string> elems;
    util::split(line, ' ', elems);
    for (auto word : elems) {
        std::cout << "next word: " << word << "\n";
    }
    return 0;
}