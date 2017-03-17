#include <array>
#include <iostream>
#include <sstream>

using namespace std;

long hex2int(const string &hexStr) {
    char *offset;
    if (hexStr.length() > 2) {
        if (hexStr[0] == '0' && hexStr[1] == 'x') {
            return strtol(hexStr.c_str(), &offset, 0);
        }
    }
    return strtol(hexStr.c_str(), &offset, 16);
}


int main() {
    array<int, 4> new_array{1, 2, 3, 4};
    cout << new_array.size() << "\n";

    for (auto a : new_array) cout << a << "\n";

    string new_str;

    cout << "input a string: " << "\n";
    getline(cin, new_str);

    try {
        cout <<
        typeof((strtol(new_str))) == long << "\n";
    }

    cout << new_str << "\n";
    return 0;
}