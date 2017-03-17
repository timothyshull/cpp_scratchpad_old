//
// Created by Tim Shull on 10/23/16.
//

#include <sstream>
#include "util.h"

void util::split(const std::string &s, char delimiter, std::vector<std::string> &elems) {
    std::stringstream ss{s};
//    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        elems.emplace_back(item);
    }
}

std::streamoff util::stream_size(std::istream &f) {
    std::istream::pos_type current_pos = f.tellg();
    if (-1 == current_pos) {
        return -1;
    }
    f.seekg(0, std::istream::end);
    std::istream::pos_type end_pos = f.tellg();
    f.seekg(current_pos);
    return end_pos - current_pos;
}

bool util::file_to_string(std::istream &f, std::string &result) {
    std::streamoff len = util::stream_size(f);
    if (len == -1) {
        return false;
    }

    result.resize(static_cast<std::string::size_type>(len));

    f.rdbuf()->sgetn(&result[0], len);
    return true;
}