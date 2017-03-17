#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

std::string file_reader(const char *fname) {
    std::ifstream f;
    f.open(fname);
    if (!f.is_open()) {
        std::cout << "Can't open " << fname << " for reading" << std::endl;
        return "";
    }
    std::stringstream s;
    std::copy(std::istreambuf_iterator<char>(f.rdbuf()), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(s));
    return s.str();
}

void stream_read_streambuf_stringstream(std::istream &f, std::string &result) {
    std::stringstream s;
    std::copy(std::istreambuf_iterator<char>(f.rdbuf()), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(s));
    std::string s_str = s.str();
    std::swap(result, s_str);
}

int main(int argc, char *argv[]) {
    const char *fname = argv[1];
    std::string s;
    std::ifstream f;
    f.open(fname);
    if (!f) {
        std::cerr << "Can't open " << fname << " for reading" << std::endl;
    } else {
        stream_read_streambuf_stringstream(f, s);
    }
}

void stream_read_streambuf_string(std::istream &f, std::string &result) {
    result.assign(std::istreambuf_iterator<char>(f.rdbuf()), std::istreambuf_iterator<char>());
}

void stream_read_streambuf(std::istream &f, std::string &result) {
    std::stringstream s;
    s << f.rdbuf();
    std::string s_str = s.str();
    std::swap(result, s_str);
}

void stream_read_string_reserve(std::istream &f, std::string &result) {
    f.seekg(0, std::istream::end);
    std::streamoff len = f.tellg();
    f.seekg(0);
    if (len > 0) {
        result.reserve(static_cast<std::string::size_type>(len));
    }
    result.assign(std::istreambuf_iterator<char>(f.rdbuf()), std::istreambuf_iterator<char>());
}

std::streamoff stream_size(std::istream &f) {
    std::istream::pos_type start_pos = f.tellg();
    if (-1 == start_pos) {
        return -1;
    }
    f.seekg(0, std::istream::end);
    std::istream::pos_type end_pos = f.tellg();
    f.seekg(start_pos);
    return end_pos - start_pos;
}

void stream_read_getline(std::istream &f, std::string &result) {
    result.clear();
    std::string line;
    while (std::getline(f, line)) {
        // TODO: (result += line) += "\n"; check this
        result += line;
        result += "\n";
    }
}

void stream_read_getline_2(std::ifstream &f, std::string &result, std::streamoff len = 0) {
    std::string line;
    result.clear();
    if (len > 0) {
        result.reserve(static_cast<std::string::size_type>(len));
    }
    while (std::getline(f, line)) {
        result += line;
        result += "\n";
    }
}

bool stream_read_string(std::istream &f, std::string &result) {
    std::streamoff len = stream_size(f);
    if (len == -1) {
        return false;
    }
    result.resize(static_cast<std::string::size_type>(len));
    f.read(&result[0], result.length());
    return true;
}

// can change C funcs to return int and pass a char **
// NOTE: this assumes result.clear() does not need to be called
bool stream_read_string_full(const char filename[], std::string &result) {
    std::ifstream f;
    f.open(filename);
    if (!f.is_open()) {
        std::cerr << "File open failure: " << filename << "\n";
        return false;
    }

    std::istream::pos_type start_pos = f.tellg();
    if (-1 == start_pos) {
        return false;
    }

    f.seekg(0, std::istream::end);
    std::streamoff len = f.tellg() - start_pos;
    f.seekg(start_pos);

    if (len == -1) {
        return false;
    }

    result.resize(static_cast<std::string::size_type>(len));
    f.read(&result[0], len);
    return true;
}

bool shortened_read_string(const char filename[], std::string &result) {
    std::ifstream f{filename, std::ios::binary | std::ios::ate};
    if (f) {
        std::istream::pos_type size = f.tellg();
        result.resize(static_cast<std::string::size_type>(size));
        f.seekg(0);
        f.read(&result[0], size);
        return true;
    } else {
        std::cerr << "File open failure: " << filename << "\n";
        return false;
    }
}