//
// Created by Tim Shull on 10/22/16.
//

#ifndef SUBPROCESS_SUBPROCESS_H
#define SUBPROCESS_SUBPROCESS_H

#include <cstdio>
#include <tuple>
#include <boost/filesystem.hpp>
#include "Preexec_fn.h"

/**
 * NOTE: review node.js child_process spawn and fork C++ code
 */

namespace subprocess {
    class Called_process_error : std::exception {
    public:
        Called_process_error(int retcode, std::string cmd);
    };

    class Value_error : std::exception {
    public:
        Value_error(std::string msg);
    };

    struct Popen_kwargs {
        std::vector<std::string> args{};
        size_t bufsize{0};
        boost::filesystem::path *executable{nullptr};
        std::fstream *stdin{nullptr};
        std::fstream *stdout{nullptr};
        std::fstream *stderr{nullptr};
        Preexec_fn *preexec_fn{nullptr};
        bool clode_fds{false};
        bool shell{false};
        boost::filesystem::path *cwd{nullptr};
        std::string *env{nullptr};
        bool universal_newlines{false};
        std::string *startupinfo{nullptr};
        int creationflags{0};
    };

    template<typename... Popen_args>
    int call(Popen_kwargs &kwargs, Popen_args...);

    template<typename... Popen_args>
    int check_call(Popen_kwargs &kwargs, Popen_args...);

    template<typename... Popen_args>
    std::string check_output(Popen_kwargs &kwargs, Popen_args...);

    std::string list2cmdline(std::vector<std::string> &seq);

    /**
     * important object methods:
     * __hash__
     * __reduce__
     * __sizeof__
     * __str__
     * __subclasshook__
     * __dict__
     * __doc__
     * __module__
     */
    class Popen {
    private:
        bool _child_created{false};
        FILE *stdin{nullptr};
        FILE *stdout{nullptr};
        FILE *stderr{nullptr};
        int pid;
        int returncode;
        char *universal_newlines;

        std::array<std::fstream, 6>
        _get_handles(std::fstream *stdin, std::fstream *stdout, std::fstream *stderr);

        int _execute_child();

    };
}

#endif //SUBPROCESS_SUBPROCESS_H
