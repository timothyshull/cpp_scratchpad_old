//
// Created by Timothy Shull on 11/19/15.
//

#include <iostream>
#include "Simple.h"

using namespace std;

namespace Records {
    Simple::Simple() {
        int mNext {2};
        int mNextSimpleVal {4};
    }

    Simple::~Simple() {
    }

    int &Simple::addStrings(string inFirstName, string inLastName) {
//        string& returnString {inFirstName};
        int var = 1;
        int& r {var};
        cout << inFirstName << ", " << inLastName << endl;
        return r;
    }

    void Simple::displayAll() {
        cout << "Public data member 1: " << kTestVal << ", public data member 2: " << kMultiplier << endl;
        cout << endl;
    }
}