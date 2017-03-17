#include <iostream>

using namespace std;

enum Traffic_light {
    red, yellow, green
};

enum Color_code : char {
    orange = 'o', blue = 'b', brown = 'r'
};

int main() {
    int a1 = red;
    int a3 = green;
    cout << a1 << endl;
    cout << a3 << endl;

    Traffic_light a4 = Traffic_light::yellow;
    cout << a4 << endl;

    cout << static_cast<char>(orange) << endl;
    return 0;
}