//
// Created by Timothy Shull on 12/25/15.
//

#include "8_3.h"

void HttpRequest::send(std::string string) {
    *sock_ << string;
}

void testRAII() {
    std::string s = "xml";
    sendMyData(s, "www.oreilly.com");
}


void sendMyData(std::string soapMsg, std::string host) {
    HttpRequest req;

    try {
        req.open();
        req.send(soapMsg);
        req.close();
    }
    catch (std::exception& e) {
        req.close();
    }
}
