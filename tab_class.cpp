#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template<typename T>
class TableFormatter {
public:
    TableFormatter(basic_ostream<T>& os) : out_{os} { }

    ~TableFormatter() { out_ << flush; }

    template<typename valT>
    void writeTableRow(const vector<valT>&, int);

private:
    basic_ostream<T>& out_;
};

template<typename T>
template<typename valT>
void TableFormatter<T>::writeTableRow(const vector<valT>& v, int width) {
    ios_base::fmtflags flags = out_.flags();

    out_.flush();
    out_ << setprecision(2) << fixed;

    for (vector<valT>::const_iterator p = v.cbegin(); p != v.end(); ++p)
        out_ << setw(width) << left << *p;

    out_ << endl;
    out_.setf(flags);
}

int main() {
    TableFormatter<char> fmt(cout);
    vector<string> vs;
    vs.push_back("Sunday");
    vs.push_back("Monday");
    vs.push_back("Tuesday");
    fmt.writeTableRow(vs, 12);
    fmt.writeTableRow(vs, 12);
    fmt.writeTableRow(vs, 12);
    vector<double> vd;
    vd.push_back(4.0);
    vd.push_back(3.0);
    vd.push_back(2.0);
    vd.push_back(1.0);
    fmt.writeTableRow(vd, 5);
}
