#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

void redirect(ostream&);

int main() {
    cout << "The first row." << end;
    redirect(cout);
    cout << "The last row." << endl;
}

void redirect(ostream& strm) {
    auto del = [&](streambuf* p) {
        strm.rdbuf(p);
    };
    unique_ptr<streambuf, decltype(del)> origBuffer(strm.rdbuf(), del);

    // redirect output into the file redirect.txt
    ofstream file("redirect.txt");
    strm.rdbuf(file.rdbuf());

    file << "one row for the file" << endl;
    strm << "one row for the stream" << endl;
}
