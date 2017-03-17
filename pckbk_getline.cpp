//
// Created by Tim Shull on 10/23/16.
//

#include <iostream>
#include <fstream>

void process(std::string &line) {
    std::cout << line << "\n";
}

int main(int argc, char *argv[]) {
    std::ifstream in{argv[1]};
    std::string line;
    while (std::getline(in, line)) {
        process(line);
    }
    return 0;
}


//    while (in >> line) {
//        std::cout << line << '\n';
//    }