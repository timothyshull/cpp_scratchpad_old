//
// Created by Tim Shull on 10/25/16.
//

#ifndef MEMORY_MAPPED_FILES_MEM_MAPPED_FILE_H
#define MEMORY_MAPPED_FILES_MEM_MAPPED_FILE_H

#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

class Mem_mapped_file_exception : std::exception {
};

class Mem_mapped_file {
public:
    Mem_mapped_file();

    explicit Mem_mapped_file(const char *filename, std::ios_base::openmode mode = std::ios_base::in);

    explicit Mem_mapped_file(const std::string &filename, std::ios_base::openmode mode = std::ios_base::in);

    Mem_mapped_file(Mem_mapped_file &&rhs);

    Mem_mapped_file &operator=(Mem_mapped_file &&rhs);

    ~Mem_mapped_file();

    void swap(Mem_mapped_file &rhs);

//    basic_filebuf <char_type, traits_type> *rdbuf() const;

    bool is_open() const;

    void open(const char *filename, std::ios_base::openmode mode = std::ios_base::in);

    void open(const std::string &filename, std::ios_base::openmode mode = std::ios_base::in);

    void close();

    std::string to_string();

private:
    int _fd{-1};
    off_t _sz;
    char *_mem;
};


Mem_mapped_file::Mem_mapped_file(const char *filename, std::ios_base::openmode mode) {
    // TODO: replace with O_RDONLY etc
//    const char* mode_str;
//    switch (mode & ~std::ios_base::ate) {
//        case std::ios_base::out:
//        case std::ios_base::out | std::ios_base::trunc:
//            mode_str = "w";
//            break;
//        case std::ios_base::out | std::ios_base::app:
//        case std::ios_base::app:
//            mode_str = "a";
//            break;
//        case std::ios_base::in:
//            mode_str = "r";
//            break;
//        case std::ios_base::in | std::ios_base::out:
//            mode_str = "r+";
//            break;
//        case std::ios_base::in | std::ios_base::out | std::ios_base::trunc:
//            mode_str = "w+";
//            break;
//        case std::ios_base::in | std::ios_base::out | std::ios_base::app:
//        case std::ios_base::in | std::ios_base::app:
//            mode_str = "a+";
//            break;
//        case std::ios_base::out | std::ios_base::binary:
//        case std::ios_base::out | std::ios_base::trunc | std::ios_base::binary:
//            mode_str = "wb";
//            break;
//        case std::ios_base::out | std::ios_base::app | std::ios_base::binary:
//        case std::ios_base::app | std::ios_base::binary:
//            mode_str = "ab";
//            break;
//        case std::ios_base::in | std::ios_base::binary:
//            mode_str = "rb";
//            break;
//        case std::ios_base::in | std::ios_base::out | std::ios_base::binary:
//            mode_str = "r+b";
//            break;
//        case std::ios_base::in | std::ios_base::out | std::ios_base::trunc | std::ios_base::binary:
//            mode_str = "w+b";
//            break;
//        case std::ios_base::in | std::ios_base::out | std::ios_base::app | std::ios_base::binary:
//        case std::ios_base::in | std::ios_base::app | std::ios_base::binary:
//            mode_str = "a+b";
//            break;
//        default:
//            mode_str = "r";
//            break;
//    }
    _fd = ::open(filename, O_RDONLY);

    if (_fd == -1) {
        // TODO: replace with custom exception
        // "error opening file: " + filename
        throw Mem_mapped_file_exception{};
    } else {
        struct stat sb;
        if (fstat(_fd, &sb) == -1) {
            // "error with fstat" + filename
            throw Mem_mapped_file_exception{};
        }
        if (!S_ISREG (sb.st_mode)) {
            // "error " + filename + " is not a file"
            throw Mem_mapped_file_exception{};
        }
        _sz = sb.st_size;
        _mem = static_cast<char *>(mmap(0, static_cast<size_t>(sb.st_size), PROT_READ, MAP_SHARED, _fd, 0));
        if (_mem == MAP_FAILED) {
            // "error memory mapping of " + filename + " failed"
            throw Mem_mapped_file_exception{};
        }
        if (::close(_fd) == -1) {
            // "error closing file " + filename
            throw Mem_mapped_file_exception{};
        }
    }
}

Mem_mapped_file::~Mem_mapped_file() {
    if (munmap(_mem, static_cast<size_t>(_sz)) == -1) {
        // "error unmapping file " + filename
        throw Mem_mapped_file_exception{};
    }
}

void Mem_mapped_file::close() {
    // TODO: check for open file here
    if (munmap(_mem, static_cast<size_t>(_sz)) == -1) {
        // "error unmapping file " + filename
        throw Mem_mapped_file_exception{};
    }
}

bool Mem_mapped_file::is_open() const {
    // TODO: check that fd is valid
    return fcntl(_fd, F_GETFD) != -1 && errno != EBADF;
}

std::string Mem_mapped_file::to_string() {
    if (is_open()) {
        return std::string{_mem};
    } else {
        // file not opened
        throw Mem_mapped_file_exception{};
    }
}


#endif //MEMORY_MAPPED_FILES_MEM_MAPPED_FILE_H
