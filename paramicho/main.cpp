#include <iostream>
#include <wordexp.h>
#include <sstream>


int main() {
//    wordexp_t exp_result;
//    char path[] {"~"};
//    wordexp(path, &exp_result, 0);
//    printf(exp_result.we_wordv[0]);
//    wordfree(&exp_result);
    std::string env_home {std::getenv("HOME")};
    env_home += "/.ssh/known_hosts";
    std::stringstream test_str;
    test_str << std::getenv("HOME") << "/.ssh/known_hosts";
    std::cout << env_home << std::endl;
    std::cout << test_str.str() << std::endl;
    std::string filename {""};
    if (filename == "") {
        filename = std::string(std::getenv("HOME")) + "/.ssh/known_hosts";
        std::cout << filename << std::endl;

    }
    return 0;
}
