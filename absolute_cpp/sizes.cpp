#include <iostream>

using namespace std;

int main() {
    short var1 = 1;
    int var2 = 2;
    long var3 = 3;
    float var4 = 1.0;
    double var5 = 2.0;
    long double var6 = 3.0;
    char var7 = 'c';
    bool var8 = false;

    cout << "Size of var1: " << sizeof(var1) << endl;
    cout << "Size of var2: " << sizeof(var2) << endl;
    cout << "Size of var3: " << sizeof(var3) << endl;
    cout << "Size of var4: " << sizeof(var4) << endl;
    cout << "Size of var5: " << sizeof(var5) << endl;
    cout << "Size of var6: " << sizeof(var6) << endl;
    cout << "Size of var7: " << sizeof(var7) << endl;
    cout << "Size of var8: " << sizeof(var8) << endl;

    return 0;
}