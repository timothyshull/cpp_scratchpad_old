#include<iostream>
#include<string>
#include<boost/filesystem.hpp>

#include"utility.h"

using boost::filesystem::path;
using boost::filesystem::initial_path;

// NOTE: a questionably reliable source timed push_back as faster than append (which was faster than +=)

int main() {
    path p{initial_path().parent_path()};
    p.append("/content1.txt");
    std::cout << p << "\n";
    std::string s;
    shortened_read_string(p.c_str(), s);

    std::string line1;
    for (auto c : s) {
        if (c == '\n') {
            break;
        }
        line1.push_back(c);
    }
    std::cout << line1 << "\n";

    std::vector<std::string> strings;
    split_lines(s, strings);

    for (auto v : strings) {
        std::cout << "one " << v << "\n";
    }
    return 0;
}