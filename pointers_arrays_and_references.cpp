//
// Created by Timothy Shull on 12/1/15.
//
#include <iostream>
#include "pointers_arrays_and_references.h"

using namespace std;

char *return_char_pointer(char &a) {
    char *p = &a;
    return p;
}