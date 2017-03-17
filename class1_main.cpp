#include <iostream>
#include "class1.h"

using namespace std;

int main() {
    class1<int> c{10};
    size_t st = sizeof(c);

    cout << "size of c is: " << st << endl;

    int new_int{10};
    int *new_int_ptr{&new_int};

    cout << new_int_ptr << "\n";
    cout << &new_int << "\n";
    *new_int_ptr = 12;
    cout << new_int << "\n";
    return 0;
}