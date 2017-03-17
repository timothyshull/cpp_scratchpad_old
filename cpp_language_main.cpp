#include <iostream>
#include "types_and_declarations.h"
#include "pointers_arrays_and_references.h"

using namespace std;

int main() {
    int a {10};
    int b {12};
    compare_ints(a, b);

    int c {13};
    int d {13};
    compare_ints(c, d);

//    intval();

    digits();

//    auto ac = alignof('c');
//    auto ai = alignof(1);
//    auto ad = alignof(2.0);
//
//    int a_b[20];
//    auto aa = alignof(a_b);
//
//    printf("%zu\n", ac);
//    printf("%zu\n", ai);
//    printf("%zu\n", ad);
//    printf("%zu\n", aa);
    char e = 'a';
    char* f = return_char_pointer(e);

    cout << f << endl;
    cout << &e << endl;

    int g {10};

    cout << g << endl;

    return 0;
}