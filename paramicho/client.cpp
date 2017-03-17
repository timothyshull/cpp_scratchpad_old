#include "client.h"

namespace paramicho {
    void SSHClient::load_system_host_keys(std::string filename) {
        if (filename == "") {
            filename = std::getenv("HOME") + "/.ssh/known_hosts";
        }
        try {
            this->_system_host_keys.load(filename);
        } catch (...) { }

        return this->_system_host_keys.load(filename);
    }

    void SSHClient::load_host_keys(std::string filename) {
        this->_host_keys_filename = filename;
        this->_host_keys.load(filename);
    }
}