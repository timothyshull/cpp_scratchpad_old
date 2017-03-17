#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void write_charset_to_file(const string& filename);

void output_file(const string& filename);

int main() {
    write_charset_to_file("charset.out.txt");
    output_file("charset.out.txt");
}

void write_charset_to_file(const string& filename) {
    ofstream file(filename);

    if (!file) {
        cerr << "Unable to output file: \"" << filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 32; i < 256; ++i) {
        file << "value: " << setw(3) << i << "   " << "char: " << static_cast<char>(i) << endl;
    }
}

void output_file(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cerr << "Unable to open input file: \"" << filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    char c;
    while (file.get(c)) {
        cout.put(c);
    }
}