//
//  main.cpp
//  files_and_regexes
//
//  Created by Tim Shull on 10/14/16.
//  Copyright © 2016 Tim Shull. All rights reserved.
//

#include <iostream>
#include <vector>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>

std::size_t buf_size = 4096;

std::vector<std::string> arguments(int argc, const char *argv[]) {
    std::vector<std::string> res;
    for (int i = 0; i != argc; ++i)
        res.push_back(argv[i]);
    return res;
}

int main(int argc, const char *argv[]) {
    std::vector<std::string> args = arguments(argc, argv);

    if (args.size() < 2) {
        std::cerr << "Usage: <input file> <output file>" << std::endl;
        exit(1);
    }

//    std::ifstream in(args[1], std::ios_base::in | std::ios_base::binary);
    std::ifstream in(args[1], std::ios_base::in);
//    std::ofstream out(args[2], std::ios_base::out | std::ios_base::binary);
    std::ofstream out(args[2], std::ios_base::out);

    char buf[buf_size];

    std::string in_string;

    do {
        std::cout << "write some shit" << std::endl;
//        std::cin.getline(buf, buf_size);
        std::getline(std::cin, in_string);
        out << in_string << std::endl;
    } while (!std::cin.eof());

    in.close();
    out.close();

//    try {
//        // Turn the args into absolute paths using native formatting
//        boost::filesystem::path src = boost::filesystem::complete(boost::filesystem::path(args[1]).native());
//        boost::filesystem::path dst = boost::filesystem::complete(boost::filesystem::path(args[2]).native());
//
//        boost::filesystem::copy_file(src, dst);
//    } catch (std::exception &e) {
//        std::cerr << e.what() << std::endl;
//    }

    return 0;
}


//#include <iostream>
//#include <fstream>
//#include <string>
//
//void f()
//{
//    std::string line;
//    while(std::getline(std::cin, line))  //input from the file in.txt
//    {
//        std::cout << line << "\n";   //output to the file out.txt
//    }
//}
//int main()
//{
//    std::ifstream in("in.txt");
//    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
//    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
//
//    std::ofstream out("out.txt");
//    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
//    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
//
//    std::string word;
//    std::cin >> word;           //input from the file in.txt
//    std::cout << word << "  ";  //output to the file out.txt
//
//    f(); //call function
//
//
//    std::cin.rdbuf(cinbuf);   //reset to standard input again
//    std::cout.rdbuf(coutbuf); //reset to standard output again
//
//    std::cin >> word;   //input from the standard input
//    std::cout << word;  //output to the standard input
//}