//
// Created by Timothy Shull on 12/14/15.
//

#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int inWidth, int inHeight) : mWidth{inWidth}, mHeight{inHeight} {
    mCells = new SpreadsheetCell *[mWidth];
    for (int i = 0; i < mWidth; i++) {
        mCells[i] = new SpreadsheetCell[mHeight];
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet &src) {
    int i, j;

    mWidth = src.mWidth;
    mHeight = src.mHeight;

    mCells = new SpreadsheetCell *[mWidth];
    for (i = 0; i < mWidth; i++) {
        mCells[i] = new SpreadsheetCell[mHeight];
    }

    for (i = 0; i < mWidth; i++) {
        for (j = 0; j < mHeight; j++) {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

Spreadsheet &Spreadsheet::operator=(const Spreadsheet &rhs) {
    int i, j;

    if (this == &rhs) {
        return *this;
    }

    for (i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;

    handleCopy(rhs, i, j);

    return *this;
}

void Spreadsheet::handleCopy(const Spreadsheet &rhs, int i, int j) {
    mWidth = rhs.mWidth;
    mHeight = rhs.mHeight;

    mCells = new SpreadsheetCell *[mWidth];
    for (i = 0; i < mWidth; i++) {
        mCells[i] = new SpreadsheetCell[mHeight];
    }

    for (i = 0; i < mWidth; i++) {
        for (j = 0; j < mHeight; j++) {
            mCells[i][j] = rhs.mCells[i][j];
        }
    }
}

int Spreadsheet::sCounter = 0;

bool Spreadsheet::inRange(int val, int upper) {
    return val < upper;
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell &cell) {
    if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
        return;
    }

    mCells[x][y] = cell;
}

SpreadsheetCell Spreadsheet::getCellAt(int x, int y) {
    SpreadsheetCell empty;
    if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
        return empty;
    }

    return mCells[x][y];
}

Spreadsheet::~Spreadsheet() {
    for (int i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }

    delete[] mCells;
}

void Spreadsheet::print() {
    for (int i = 0; i < mHeight; i++) {
        for (int j = 0; j < mWidth; j++) {
            std::cout << this->getCellAt(j, i).getString() << '\t' << '\t';
            if (j == mWidth - 1)
                std::cout << std::endl;
        }
    }
}