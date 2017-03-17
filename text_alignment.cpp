#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::fmtflags flags = cout.flags();
    int width{20};

    string first{"Richard"};
    string last{"Stevens"};
    string citystate{"Tucson, AZ"};

    cout << left << setw(width) << first << setw(width) << last << setw(width) << citystate << endl;
    cout.flags(flags);
}

// iomanipulators
// leftright
// setw(int)
// setfill(int c)
// boolalphanoboolalpha
// endl
// ends
// flush