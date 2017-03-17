#include <fstream>
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
    ifstream file;

    for (int i = 1; i < argc; ++i) {
        file.open(argv[i]);

        char c;
        while (file.get(c)) {
            cout.put(c);
        }

        // or std::cout << file.rdbuf(); <- dump all contents to stdout

        file.clear();
        file.close();
    }
}
