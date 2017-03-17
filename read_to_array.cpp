#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::string line;
    std::vector<std::string> ctnr;
//    std::ifstream myfile("/Users/skull/Documents/Programming/Cpp/read_to_array/test.txt");
    std::ifstream myfile("/Users/skull/Documents/Programming/Cpp/read_to_array/test2.txt");
    /*if (myfile.is_open()) {
        while (getline(myfile, line)) {
            ctnr.push_back(line);
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file";
    }

    for (std::string x : ctnr)
        std::cout << x << std::endl;*/

    int counter {0};

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            ++counter;
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file";
    }

    std::cout << counter << std::endl;

    return 0;
}