#ifndef PARAMICHO_CLIENT_H
#define PARAMICHO_CLIENT_H

#include "util.h"

class HostKeys;
class RejectPolicy;
class Transport;

namespace paramicho {
    class SSHClient : public ClosingContextManager {
    private:
        HostKeys _system_host_keys;
        HostKeys _host_keys;
        std::string _host_keys_filename;
        std::string _log_channel;
        RejectPolicy _policy;
        Transport _transport;
        std::string agent;
    public:
        void load_system_host_keys(std::string filename = "");
        void load_host_keys(std::string filename);
//        load_host_keys
//                save_host_keys
//        get_host_keys
//                set_log_channel
//        set_missing_host_key_policy
//                _families_and_addresses
//        connect
//                close
//        exec_command
//                invoke_shell
//        open_sftp
//                get_transport
//        _auth
//                _log
//        _agent
//                _host_keys
//        _host_keys_filename
//                _log_channel
//        _policy
//                _system_host_keys
//        _transport
    };
}


#endif //PARAMICHO_CLIENT_H
