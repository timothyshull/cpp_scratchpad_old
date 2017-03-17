//
// Created by Timothy Shull on 12/25/15.
//

#include "8_9_1.h"

void MyAppClass::myMethod() {
    std::string val;
    config_->getKey("Foo", "Bar", val);
}


void testAbstract() {
    std::ifstream in{"foo.txt"};
    TXTConfigFile cfg{in};

    MyAppClass m;
    m.setConfigObj(&cfg);
    m.myMethod();
}
