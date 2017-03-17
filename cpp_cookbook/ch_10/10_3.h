//
// Created by Timothy Shull on 12/31/15.
//

#ifndef CPP_COOKBOOK_10_3_H
#define CPP_COOKBOOK_10_3_H

#include <iostream>

inline std::ios_base& floatnormal(std::ios_base& io) {
    io.setf(0, std::ios_base::floatfield);
    return io;
}

void customStreamManip();

template<typename T, typename C>
class ManipInfra {
public:

    ManipInfra(std::basic_ostream<C>& (* pFun)(std::basic_ostream<C>&, T) T val) : manipFun_{pFun}, val_{val} { }

    void operator()(std::basic_ostream<C>& os) const { manipFun_(os, val_); }

private:
    T val_;

    std::basic_ostream<C>& (* manipFun_)(std::basic_ostream<C>&, T);
};

template<typename T, typename C>
std::basic_ostream<C>& operator<<(std::basic_ostream<C>& os, const ManipInfra<T, C>& manip) {
    manip(os);
    return os;
};

std::ostream& setTheWidth(std::ostream& os, int n) {
    os.width(n);
    return os;
}

ManipInfra<int, char> setWidth(int n) {
    return ManipInfra<int, char>(setTheWidth, n);
};

std::ostream& setTheFillChar(std::ostream& os, char c) {
    os.fill(c);
    return os;
}

ManipInfra<char, char> setFill(char c) {
    return ManipInfra<char, char>(setTheFillChar, c);
};

void customStreamManip2();

#endif //CPP_COOKBOOK_10_3_H
