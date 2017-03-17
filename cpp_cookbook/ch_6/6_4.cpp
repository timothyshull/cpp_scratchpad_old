//
// Created by Timothy Shull on 12/20/15.
//

#include "6_4.h"
#include "sample_class.h"
#include <iostream>
#include <vector>

static const int NUM_OBJECTS = 10;

void pointersInVector() {
    std::vector<SampleClass<int>*> vec;

    SampleClass<int>* p = nullptr;

    for (int i = 0; i < NUM_OBJECTS; i++) {
//        p = new SampleClass<int>();
//        vec.push_back(p);
        vec.push_back(new SampleClass<int>());
    }

    for (std::vector<SampleClass*>::iterator pObj = vec.begin(); pObj != vec.end(); ++pObj)
        delete *pObj;

    vec.clear();
}
