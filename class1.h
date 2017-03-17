#ifndef EXPERIMENTS3_CLASS1_H
#define EXPERIMENTS3_CLASS1_H

template<typename T>
class class1 {
    using value_type = T;
    value_type data_member;
public:
    class1(T t) : data_member{t} { }
};

#endif //EXPERIMENTS3_CLASS1_H
