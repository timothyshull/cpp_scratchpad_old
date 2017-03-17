//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_6_9_H
#define CPPCOOKBOOK_6_9_H

#include <set>
#include <string>
#include <map>

class DBConn {
public:
    void beginTxn();

    void endTxn();

    void execSql(std::string&);
};

class SimpleTxnLog {
    std::map<std::string, std::set<std::string>*> log_;
    DBConn* conn_;
public:
    SimpleTxnLog() { }

    ~SimpleTxnLog() { purge(); }

    void addTxn(const std::string&, const std::string&);

    void apply();

    void purge();
};


#endif //CPPCOOKBOOK_6_9_H
