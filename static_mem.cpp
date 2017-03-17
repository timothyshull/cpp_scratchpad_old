#include <iostream>

using namespace std;

class TestClass {
public:
    static int n;
};

int TestClass::n = 6;

int main() {
    TestClass newTest = TestClass();
    cout << newTest.n << endl;
    return 0;
}