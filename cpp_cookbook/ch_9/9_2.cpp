//
// Created by Timothy Shull on 12/25/15.
//

#include "9_2.h"
#include <iostream>


const char* basic_error::what() const throw() {
    return str_.c_str();
}

Device::Device(int devno) {
    if (devno == 2)
        throw basic_error {"Big problem"};
}

Broker::Broker(int devno1, int devno2) : dev1_{nullptr}, dev2_{nullptr} {
    try {
        dev1_ = new Device(devno1);
        dev2_ = new Device(devno2);
    } catch (...) {
        delete dev1_;
        throw;
    }
}

Broker::~Broker() {
    delete dev1_;
    delete dev2_;
}

void tryExceptionSafeCtor() {
    try {
        Broker b(1, 2);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}
