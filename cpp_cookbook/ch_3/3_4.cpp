//
// Created by Timothy Shull on 12/18/15.
//

#include "3_4.h"
#include <iostream>
#include <boost/format.hpp>

std::string int2hex(int i) {
    return boost::str(boost::format("%x") % i);
}