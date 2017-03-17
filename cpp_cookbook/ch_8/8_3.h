//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_3_H
#define CPP_COOKBOOK_8_3_H

#include <string>

class Socket {
    std::string hostname_;
public:
    Socket(const std::string& hostname) : hostname_{hostname} { };

    void operator<<(std::string hostname) {
        hostname_ += hostname;
    };
};

class HttpRequest {
    Socket* sock_;
public:
    HttpRequest() { }

    HttpRequest(const std::string& hostname) : sock_{new Socket(hostname)} { };

    virtual ~HttpRequest() { delete sock_ };

    void send(std::string);
};

void testRAII();

void sendMyData(std::string, std::string);

#endif //CPP_COOKBOOK_8_3_H
