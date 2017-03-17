#include <iostream>
#include <sys>

using namespace std;

int main() {
    string test;
    cout << "Enter input :\n";
    while (getline(std::cin, test) && !cin.eof()) {
        // also !cin.bad()
        cout << test << endl;
        size_t test_size_t{2};
        ::new()
    }
    return 0;
}