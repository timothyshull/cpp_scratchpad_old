// Self-test pg 23

#include <iostream>

using namespace std;

int main() {
    int x = 2;
    int y = 3;
    int z = 4;

    // 4.1
    cout << "3 * x = " << 3 * x << endl;

    // 4.2
    cout << "3 * x + y = " << 3 * x + y << endl;

    // 4.3
    cout << "3 * x / 7 = " << (3 * x) / 7 << endl;

    // 4.4
    cout << "3 * x + y / z + 2 = " << (3 * x + y) / (z + 2) << endl;

    // 5
    char a = 'b';
    char b = 'c';
    char c = a;

    cout << a << b << c << 'c' << endl;
    // ans: bcbc

    // 6
    int number = (1/3) * 3;
    cout << "(1/3) * 3 is equal to " << number << endl;
    // ans: 0

    // 7
    int var1;
    int var2;

    cin >> var1;
    cin >> var2;
    cout << var1 / var2 << endl;
    cout << var1 % var2 << endl;

    // 8
    // Even though both c and f are doubles, (9/5) is evaluated first to 1, so the resulting expression is 1 * 20.0 + 32.0
    double c2 = 20;
    double f;
    f = (9/5) * c2 + 32.0;
    cout << f << endl;
    f = (9.0 / 5.0) * c2 + 32.0;
    cout << f << endl;

    return 0;
}