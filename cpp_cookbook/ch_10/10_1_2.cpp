//
// Created by Timothy Shull on 12/25/15.
//

#include "10_1_2.h"

void testTableFormatter() {
    TableFormatter<char> fmt(std::cout);

    std::vector<std::string> vs;

    vs.push_back("Sunday");
    vs.push_back("Monday");
    vs.push_back("Tuesday");

    fmt.writeTableRow(vs, 12);
    fmt.writeTableRow(vs, 12);
    fmt.writeTableRow(vs, 12);

    std::vector<double> vd;

    vd.push_back(4.0);
    vd.push_back(3.0);
    vd.push_back(2.0);
    vd.push_back(1.0);

    fmt.writeTableRow(vd, 5);
}
