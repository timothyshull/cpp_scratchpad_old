//
// Created by Timothy Shull on 12/25/15.
//

#include "8_9.h"

Singleton* Singleton::inst_ = nullptr;

Singleton& Singleton::operator=(const Singleton& singleton) {
    return *inst_;
}

Singleton* Singleton::getInstance() {
    if (inst_ == nullptr)
        inst_ = new Singleton();

    return inst_;
}

int Singleton::getValue_() const {
    return value_;
}

void Singleton::setValue(int i) {
    value_ = i;
}
