//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_5_H
#define CPP_COOKBOOK_8_5_H

class OneStatic {
public:
    OneStatic() { }

    constexpr int getCount() { return count; }

protected:
    static int count;
};

void testOneStatic();

#endif //CPP_COOKBOOK_8_5_H
