//
// Created by Tim Shull on 10/22/16.
//

#include "subprocess.h"

namespace subprocess {
    template<typename... Popen_args>
    int call(Popen_kwargs &kwargs, Popen_args...) {
        Popen process{kwargs, Popen_args...};
        return process.wait();
    }

    template<typename... Popen_args>
    int check_call(Popen_kwargs &kwargs, Popen_args...) {
        int retcode = call(kwargs, Popen_args...);
        if (retcode) {
            auto cmd = kwargs.args;
            if (cmd.empty()) {
                cmd = Popen_args;
                throw Called_process_error{retcode, Popen_args};
            }
        }
        return 0;
    }

    template<typename... Popen_args>
    std::string check_output(Popen_kwargs &kwargs, Popen_args...) {
        if (kwargs.stdout != nullptr) {
            throw Value_error("stdout argument not allowed, it will be overridden.");
        }
        kwargs.stdout = PIPE;
        Popen process{kwargs, Popen_args...};
        auto output_and_err = process.communicate();
        auto retcode = process.poll();
        if (retcode) {
            auto cmd = kwargs.args;
            if (cmd.empty()) {
                cmd = Popen_args;
                throw Called_process_error{retcode, output_and_err.get(0), Popen_args...};
            }
        }
        return output_and_err.get(0);
    }

    std::string list2cmdline(std::vector<std::string> seq) {
        std::vector<std::string> result{};
        bool needquote{false};
        for (auto arg : seq) {
            if (!result.empty()) {
                result.emplace_back(" ");
            }

            needquote = arg.find(' ') != std::string::npos or arg.find('\t') != std::string::npos or arg == "";

            if (needquote) {
                result.emplace_back("\"");
            }

            std::string bs_buf{""};
            for (auto c : arg) {
                switch (c) {
                    case '\\': {
                        bs_buf.push_back(c);
                        break;
                    }
                    case '\"': {
                        break;
                    }
                    default:
                        if (!bs_buf.empty()) {
                            result.emplace_back(bs_buf);
                            bs_buf = "";
                        }
                        result.emplace_back(c);
                }
            }

            if (!bs_buf.empty()) {
                result.emplace_back(bs_buf);
            }
        }
        std::string output;
        for (const auto &arg : result) {
            output += arg;
        }
        return output;
    };
}


