#include <iostream>
#include <array>
#include <vector>

std::string int_to_string(int val)
{
    std::string s;
    bool neg{val < 0};
    while (val) {
        s += '0' + val % 10;
        val /= 10;
    }
    if (neg) { s += '-'; }
    return {s.rbegin(), s.rend()};
}

int string_to_int(std::string& str)
{
    int ret{0};
    int mult{1};
    bool neg{false};

    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        if (*it == '-') {
            neg = true;
            break;
        }
        ret += static_cast<int>((*it - '0') * mult);
        mult *= 10;
    }
    return neg ? -ret : ret;
}

int string_to_int(std::string&& str)
{
    int ret{0};
    int mult{1};
    bool neg{false};

    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        if (*it == '-') {
            neg = true;
            break;
        }
        ret += static_cast<int>((*it - '0') * mult);
        mult *= 10;
    }
    return neg ? -ret : ret;
}

int main(int argc, char* argv[])
{
    // std::array<int, 3> a{1, 2, 3};
    // std::vector<int> v{1, 2, 3};
    std::array<std::array<int, 3>, 3> a{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    std::vector<std::vector<int>> v{{1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9}};
    std::cout << int_to_string(14567) << "\n";
    std::cout << string_to_int("-5467") << "\n";
    std::string tmp{"str"};
    std::for_each(tmp.begin(), tmp.end(), [](char& c) { std::cout << typeid(c).name(); });

    std::string str1 = "Text with some   spaces";
    str1.erase(std::remove(str1.begin(), str1.end(), ' '), str1.end());
    std::cout << str1 << '\n';
    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(std::remove_if(str2.begin(), str2.end(), [](char x) { return std::isspace(x); }), str2.end());
    return 0;
}

std::streamoff stream_size(std::istream& f)
{
    std::istream::pos_type current_pos = f.tellg();
    if (-1 == current_pos) {
        return -1;
    }
    f.seekg(0, std::istream::end);
    std::istream::pos_type end_pos = f.tellg();
    f.seekg(current_pos);
    return end_pos - current_pos;
}

bool stream_read_string(std::istream& f, std::string& result)
{
    std::streamoff len = stream_size(f);
    if (len == -1) {
        return false;
    }
    result.resize(static_cast<std::string::size_type>(len));
    f.read(&result[0], result.length());
    return true;
}
