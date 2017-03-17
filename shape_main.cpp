#include <iostream>
#include "square.h"
#include "A.h"
#include "B.h"

using std::cout;
using std::endl;
using experiments4::Square;
using experiments4::A;
using experiments4::B;

int main() {
    Square s{12};
    cout << s.get_area() << endl;
    cout << s.get_perimeter() << endl;
    B b;
    A* bp{&b};
    bp->print_message();

    return 0;
}