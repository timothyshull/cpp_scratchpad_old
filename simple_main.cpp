#include <iostream>
#include "Simple.h"

using namespace std;
using namespace Records;

int main() {
    Simple test;
    string one {"t"};
    string two {"s"};
    string three {one + two};
    int &another {test.addStrings(one, two)};
    cout << another << endl;
    test.displayAll();
    cout << three << endl;
    return 0;
}