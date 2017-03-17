//
// Created by Timothy Shull on 12/14/15.
//

#ifndef PROFESSIONALCPP_SPREADSHEET_H
#define PROFESSIONALCPP_SPREADSHEET_H

#include "SpreadsheetCell.h"
#include <iostream>

class Spreadsheet {
private:

protected:
    bool inRange(int, int);
    int mWidth;
    int mHeight;
    SpreadsheetCell **mCells;
public:
    static int sCounter;

    Spreadsheet(int, int);

    Spreadsheet(const Spreadsheet &); // Copy constructor

    Spreadsheet &operator=(const Spreadsheet &);

    ~Spreadsheet();

    void setCellAt(int, int, const SpreadsheetCell &);

    SpreadsheetCell getCellAt(int, int);

    void print();

    void handleCopy(const Spreadsheet &rhs, int i, int j);
};

#endif //PROFESSIONALCPP_SPREADSHEET_H
