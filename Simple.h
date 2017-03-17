//
// Created by Timothy Shull on 11/19/15.
//

#include <iostream>

#ifndef INTERVIEWS_SIMPLE_H
#define INTERVIEWS_SIMPLE_H

namespace Records {
    const int kTestVal = 100;
    const int kMultiplier = 1000;

    class Simple {
    public:
        Simple();

        ~Simple();

        int &addStrings(std::string inFirstName, std::string inLastName);

        void displayAll();

    protected:
        int mNext;
        int mNextSimpleVal;
    };
}

#endif //INTERVIEWS_SIMPLE_H
