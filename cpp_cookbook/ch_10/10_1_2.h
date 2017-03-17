//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_10_1_2_H
#define CPP_COOKBOOK_10_1_2_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

template<typename T>
class TableFormatter {
public:
    TableFormatter(std::basic_ostream<T>& os) : out_{os} { }

    ~TableFormatter() { out_ << std::flush; }

    template<typename valT>
    void writeTableRow(const std::vector<valT>& v, int width);

private:
    std::basic_ostream<T>& out_;
};

template<typename valT>
void TableFormatter::writeTableRow(const std::vector<valT>& v, int width) {
    std::ios_base::fmtflags flags = out_.flags();

    out_.flush();
    out_ << std::setprecision(2) << std::fixed;

    for (std::vector<valT>::const_iterator p = v.begin(); p != v.end(); ++p)
        std::cout << std::setw(width) << std::left << *p;

    out_ << std::endl;
    out_.setf(flags);
}

void testTableFormatter();

#endif //CPP_COOKBOOK_10_1_2_H
