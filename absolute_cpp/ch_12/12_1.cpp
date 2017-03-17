#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::endl;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: exercise_1 infile_name" << endl;
        exit(1);
    }


    ifstream inStream;
    ofstream outStream;

    inStream.open("infile.txt");
    outStream.open("outfile.txt");

    int first, second, third;
    inStream >> first >> second >> third;
    outStream << "Sum: " << first + second + third << endl;

    inStream.close();
    outStream.close();

    return 0;
}