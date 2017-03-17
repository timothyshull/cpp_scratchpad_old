//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_6_7_2_H
#define CPPCOOKBOOK_6_7_2_H

#include <string>
#include <unordered_map>

class Session {
    static int count_;
    int sessionId_;
public:
    Session();
};

class SessionManager {
    std::unordered_map<std::string, Session*> sessionMap_;
public:
    SessionManager() : sessionMap_{500} { }

    ~SessionManager();

    Session* addSession(const std::string&);

    Session* getSession(const std::string&);
};

#endif //CPPCOOKBOOK_6_7_2_H
