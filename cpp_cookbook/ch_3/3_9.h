//
// Created by Timothy Shull on 12/19/15.
//

#ifndef CPPCOOKBOOK_3_9_H
#define CPPCOOKBOOK_3_9_H

#include <iostream>
#include <limits>
#include <vector>
#include <boost/variant.hpp>
#include <boost/mpl/for_each.hpp>
#include <cxxabi.h>

using var_types = boost::variant<
        short,
        int,
        long,
        float,
        double,
        long double,
        unsigned short,
        unsigned int,
        unsigned long>;

template<typename T>
void showMinMax() {
    std::cout << "min: " << std::numeric_limits<T>::min() << std::endl;
    std::cout << "max: " << std::numeric_limits<T>::max() << std::endl;
    std::cout << std::endl;
}

class Printer {
public:
    template<typename T>
    void operator()(T t) {
        int status;
        T x;
        const std::type_info& ti = typeid(x);

        std::string realname = abi::__cxa_demangle(ti.name(), 0, 0, &status);

        std::cout << realname << ":" << std::endl;
        showMinMax<T>();
    }
};

void printLimits() {
    boost::mpl::for_each<var_types::types>(Printer());
}

/*void printLimits() {
    printLimitForType<short>();
    printLimitForType<int>();
    printLimitForType<long>();
    printLimitForType<float>();
    printLimitForType<double>();
    printLimitForType<long double>();
    printLimitForType<unsigned short>();
    printLimitForType<unsigned int>();
    printLimitForType<unsigned long>();
}*/

#endif //CPPCOOKBOOK_3_9_H
