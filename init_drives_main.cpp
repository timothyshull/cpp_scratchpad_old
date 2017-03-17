#include <iostream>
#include "library/init_drives_library.h"

int main() {
    std::map<std::string, std::string> exe_map = init_drives::get_exe();

    using it_type = std::map<std::string, std::string>::iterator;

    for (it_type it = exe_map.begin(); it != exe_map.end(); it++) {
        std::cout << "key: " << it->first << std::endl;
        std::cout << "value: " << it->second << std::endl;
    }

    init_drives::add_bootstrap_env();

    std::cout << ::getenv("LD_LIBRARY_PATH") << std::endl;

    return 0;
}