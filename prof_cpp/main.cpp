#include "SpreadsheetCell.h"
#include "Spreadsheet.h"
#include <iostream>
#include <boost/format.hpp>

int main() {
//    std::cout << boost::format("%2% %1%") % 36 % 77 << std::endl;
//
//    boost::format fmter("%2% %1%");
//    fmter % 35;
//    fmter % 78;
//
//    std::cout << fmter << std::endl;
//
//    std::string s = fmter.str();
//
//    std::cout << s << std::endl;
//
//    SpreadsheetCell myCell, anotherCell;
//    myCell.setValue(6);
//    anotherCell.setValue(myCell.getValue());
//
//    std::cout << "Cell 1 value: " << myCell.getValue() << std::endl;
//    std::cout << "Cell 2 value: " << anotherCell.getValue() << std::endl;
//
//    SpreadsheetCell *myCell3 = new SpreadsheetCell();
//
//    myCell3->setValue(3.7);
//
//    std::cout << "Cell 3 value: " << myCell3->getValue() << ", String representation: " << myCell3->getString() << std::endl;
//    delete myCell3;
//
//    SpreadsheetCell aThirdCell("test");
//    SpreadsheetCell aFourthCell(4.4);
//    SpreadsheetCell *aThirdCellp = new SpreadsheetCell("4.4");
//    std::cout << "aThirdCell: " << aThirdCell.getValue() << std::endl;
//    std::cout << "aFourthCell: " << aFourthCell.getValue() << std::endl;
//    std::cout << "aThirdCellp: " << aThirdCellp->getValue() << std::endl;
//    delete aThirdCellp;


    Spreadsheet s1(4, 3);
    s1.setCellAt(0, 0, SpreadsheetCell(4.3));
    s1.setCellAt(0, 1, SpreadsheetCell(0.6));
    s1.setCellAt(1, 2, SpreadsheetCell(5.4));
    s1.setCellAt(3, 2, SpreadsheetCell(7.0));
    s1.print();

    std::cout << std::endl;

    const Spreadsheet &s1Ref = s1;
    Spreadsheet s2(s1Ref);
    s2.print();

    Spreadsheet s3 = s2;

    std::cout << std::endl;

    s3.print();

    std::cout << s3.sCounter << std::endl;

    s3.sCounter++;

    std::cout << s3.sCounter << std::endl;

    std::cout << s1.sCounter << std::endl;

    s1.sCounter--;

    std::cout << s3.sCounter << std::endl;


    return 0;
}