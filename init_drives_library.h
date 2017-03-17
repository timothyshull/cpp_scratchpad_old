#ifndef DRIVE_FORMATTING_INIT_DRIVES_LIBRARY_H
#define DRIVE_FORMATTING_INIT_DRIVES_LIBRARY_H

#include <string>
#include <map>

namespace init_drives {
    void rtrim(std::string &s, char c);

    std::string which(const char *);

    std::map<std::string, std::string> get_exe();

    void add_bootstrap_env();
}

#endif //DRIVE_FORMATTING_INIT_DRIVES_LIBRARY_H
