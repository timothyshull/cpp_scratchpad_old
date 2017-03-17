//
// Created by Tim Shull on 10/23/16.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "util.h"

void do_something_with(const char chunk[]) {
    std::cout << chunk << " \n\nbreak\n";
}


int main(int argc, char *argv[]) {
    try {
        std::ifstream in{argv[1]};
        auto _ = util::finally([&in] {in.close();});
        static const size_t buf_size{4096};
        char chunk[buf_size];
        for (;;) {
            in.read(&chunk[0], buf_size);
            if (in.gcount() < 1) {
                break;
            }
            do_something_with(chunk);
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
