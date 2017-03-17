#include <fstream>
#include <iostream>

using namespace std;

void print_file_twice(const char*);

int main (int argc, char* argv[]) {
    ifstream file;

    for (int i = 1; i < argc; ++i) {
        print_file_twice(argv[1]);
    }
}

void print_file_twice(const char* filename) {
    ifstream file(filename);
    cout << file.rdbuf();
    file.seekg(0);
    cout << file.rdbuf();
}
