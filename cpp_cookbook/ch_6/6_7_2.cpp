//
// Created by Timothy Shull on 12/20/15.
//

#include "6_7_2.h"

int Session::count_ = 0;

Session::Session() {
    count_ += 1;
    sessionId_ = count_;
}

SessionManager::~SessionManager() {
    for (auto s : sessionMap_)
        delete s.second;
}

Session* SessionManager::addSession(const std::string& login) {
    Session* p = nullptr;

    if (!(p = getSession(login))) {
        p = new Session();
        sessionMap_[login] = p;
    }
    return p;
}

Session* SessionManager::getSession(const std::string& login) {
    return sessionMap_[login];
}