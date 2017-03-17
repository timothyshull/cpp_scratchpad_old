#include <iostream>

using namespace std;

int main() {
    string s = "foo";
    s.append(20 - s.length(), 'x');
    cout << s << endl;
    s.insert(s.begin(), 40 - s.length(), 'a');
    cout << s << endl;
    return 0;
}