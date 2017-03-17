#include <iostream>
#include "node.h"
#include "linked_list.h"

using namespace std;
using namespace experiments;

int main() {
    node<int> foo;
    foo.set_data(10);
    node<int> bar;
    bar.set_data(11);
    linked_list<int> test;
    test.push_back(10);
    test.push_back(12);
    test.push_back(13);
    test.push_back(14);
    test.push_back(15);
    test.print();
//    foo.set_next(std::unique_ptr<node<int>*>(&bar));
//    cout << foo.get_next()->get_data() << endl;
//    cout << "Hello, World!" << endl;

    return 0;
}