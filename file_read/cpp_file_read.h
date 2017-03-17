#ifndef FILE_READ_CPP_FILE_READ_H
#define FILE_READ_CPP_FILE_READ_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

std::string file_reader(const char *fname);

void stream_read_streambuf_stringstream(std::istream &f, std::string &result);

void stream_read_streambuf_string(std::istream &f, std::string &result);

void stream_read_streambuf(std::istream &f, std::string &result);

void stream_read_string_reserve(std::istream &f, std::string &result);

std::streamoff stream_size(std::istream &f);

void stream_read_getline(std::istream &f, std::string &result);

void stream_read_getline_2(std::ifstream &f, std::string &result, std::streamoff len = 0);

bool stream_read_string(std::istream &f, std::string &result);

bool stream_read_string_full(std::istream &f, std::string &result);

#endif //FILE_READ_CPP_FILE_READ_H
