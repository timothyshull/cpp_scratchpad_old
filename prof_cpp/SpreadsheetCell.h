//
// Created by Timothy Shull on 12/6/15.
//

#ifndef PROFESSIONALCPP_SPREADSHEETCELL_H
#define PROFESSIONALCPP_SPREADSHEETCELL_H

#include <string>


class SpreadsheetCell {
protected:
    double mValue;
    std::string mString;

    std::string doubleToString(double);

    double stringToDouble(const std::string &);

public:
    SpreadsheetCell();

    explicit SpreadsheetCell(double);

    explicit SpreadsheetCell(const std::string &);

    SpreadsheetCell(const SpreadsheetCell &);

    SpreadsheetCell &operator=(const SpreadsheetCell &);

    void setValue(double);

    double getValue();

    void setString(const std::string &);

    std::string getString();
};


#endif //PROFESSIONALCPP_SPREADSHEETCELL_H
