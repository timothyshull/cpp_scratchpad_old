//
// Created by Timothy Shull on 1/4/16.
//

#include "6_2_2.h"
#include <assert.h>
#include <iostream>

void f(int a, int b) {
    bool b1 {a==b};
    if (b1) {
        assert(b1);
        std::cout << "bool from logical operation returned true" << std::endl;
    } else {
        assert(!b1);
        std::cout << "bool from logical operation returned false" << std::endl;
    }
}

bool is_open(File* file) {
    return file->filestream.is_open();
}

bool greater(int a, int b) {
    return a > b;
}

void f(int i) {
    bool b {i!=0};
    assert(b);
}


void g(int* p) {
    bool b = p;
    bool b2 {p!=nullptr};

    if (p) {
        assert(b);
        assert(b2);
    }
}

// Helpers

File::File(std::string filename) {
    filestream.open(filename);
}
