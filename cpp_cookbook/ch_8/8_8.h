//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_8_H
#define CPP_COOKBOOK_8_8_H

class UniqueID {
protected:
    static int nextID;
public:
    int id;

    UniqueID();

    UniqueID(const UniqueID&);

    UniqueID& operator=(const UniqueID&);
};

void testClassID();

#endif //CPP_COOKBOOK_8_8_H
