//
// Created by Tim Shull on 10/23/16.
//

#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, char *argv[]) {
    std::ifstream in{argv[1]};
    std::stringstream ss;
//    std::string line;
//    while (std::getline(in, line)) {
//        ss << line;
//        ss << "\n";
//    }
//    while (in >> line) {
//        in_ss << line;
//    }
    ss << in.rdbuf();
    std::cout << ss.str() << "\n";
    return 0;
}
