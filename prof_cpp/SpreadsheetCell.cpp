//
// Created by Timothy Shull on 12/6/15.
//

#include "SpreadsheetCell.h"

#include <iostream>
// #include <string>
// #include <cstdlib>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

SpreadsheetCell::SpreadsheetCell() : mValue{0}, mString{doubleToString(0)} { }

SpreadsheetCell::SpreadsheetCell(double inValue) : mValue{inValue},
                                                   mString{SpreadsheetCell::doubleToString(inValue)} { }

SpreadsheetCell::SpreadsheetCell(const std::string &inString) : mValue{SpreadsheetCell::stringToDouble(inString)},
                                                                mString{inString} { }

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &src) : mValue{src.mValue},
                                                               mString{src.mString} { }

SpreadsheetCell &SpreadsheetCell::operator=(const SpreadsheetCell &rhs) {
    if (this == &rhs) {
        return *this;
    }
    mValue = rhs.mValue;
    mString = rhs.mString;
    return *this;
}

void SpreadsheetCell::setValue(double inValue) {
    mValue = inValue;
    mString = doubleToString(mValue);
}

double SpreadsheetCell::getValue() {
    return mValue;
}

void SpreadsheetCell::setString(const std::string &inString) {
    mString = inString;
    mValue = stringToDouble(mString);
}

std::string SpreadsheetCell::getString() {
    return mString;
}

/*// using an ostream
std::string SpreadsheetCell::doubleToString(double inValue) {
    std::ostringstream ostr;

    ostr << inValue;
    return ostr.str();
}

// using an istream
double SpreadsheetCell::stringToDouble(std::string inString) {
    double temp;

    std::istringstream istr{inString};

    istr >> temp;
    if (istr.fail() || !istr.eof())
        return 0;

    return temp;
}

// using ctsdlib strtod
double SpreadsheetCell::stringToDouble(std::string inString) {
    return strtod(inString.c_str(), nullptr);
}*/

std::string SpreadsheetCell::doubleToString(double inValue) {
    std::string temp;

    try {
        temp = (boost::format("%s") % inValue).str();
    } catch (boost::io::format_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return temp;
}

double SpreadsheetCell::stringToDouble(const std::string &inString) {
    double temp;

    try {
        temp = boost::lexical_cast<double>(inString);
    } catch (boost::bad_lexical_cast &e) {
        std::cerr << "Bad cast: " << e.what() << std::endl;
    }

    return temp;
}