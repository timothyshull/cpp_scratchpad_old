#include<fstream>
#include<iostream>

#include"utility.h"

bool shortened_read_string(const char filename[], std::string &result) {
    std::ifstream f{filename, std::ios::binary | std::ios::ate};
    if (f) {
        std::istream::pos_type size = f.tellg();
        result.resize(static_cast<std::string::size_type>(size));
        f.seekg(0);
        f.read(&result[0], size);
        return true;
    } else {
        std::cerr << "File open failure: " << filename << "\n";
        return false;
    }
}

//void split_lines(std::string &str, std::vector<std::string> &vec) {
//    std::string tmp;
//    for (auto c : str) {
//        if (c == '\n') {
//            vec.emplace_back(tmp);
//            tmp.clear();
//        } else {
//            tmp.push_back(c);
//        }
//    }
//}

void split_lines(std::string &str, std::vector<std::string> &vec) {
    std::string::size_type i{0};
    std::string::size_type j{0};

    do {
        j = str.find('\n', i);
        vec.emplace_back(str.substr(i, j - i));
        i = j + 1;
    } while (j != std::string::npos);
}

// cookbook
void rtrim(std::string &s, char c) {
    if (s.empty()) {
        return;
    }

    std::string::iterator p;
    for (p = s.end(); p != s.begin() && *--p == c;) {}

    if (*p != c) {
        p++;
    }

    s.erase(p, s.end());
}

void rtrimws(std::string &s) {
    rtrimws(s, isspace);
}

void rtrimws(std::wstring &ws) {
    rtrimws(ws, iswspace);
}
