#include <iostream>
#include "ListElement.h"

void Func(int &x, const int &y);

int main() {
    int aa{10};
    int bb{11};
    ListElement<int> a = ListElement<int>(aa);
    ListElement<int> b = ListElement<int>(bb);
    a.setNext(&b);
    std::cout << a.getNext()->getValue() << std::endl;

    // pass by reference to const example
    int a1 = 5, a2 = 8;
    std::cout << "a1 = " << a1 << "\ta2 = " << a2 << std::endl;

    // legal call
    Func(a1, a2);
    std::cout << "a1 = " << a1 << "\ta2 = " << a2 << std::endl;

    // legal call
    Func(a1, 20);
    std::cout << "a1 = " << a1 << "\ta2 = " << a2 << std::endl;

    /*
   // ILLEGAL call
   Func(20, a2);
   cout << "a1 = " << a1 << "\ta2 = " << a2 << '\n';
*/

    return 0;
}


void Func(int &x, const int &y)
// x CAN be changed.  y cannot
{
    x = x * 2;
//   y = y * 2;		// this is illegal

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}