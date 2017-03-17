//
// Created by Timothy Shull on 12/20/15.
//

#include "6_9.h"
#include <iostream>

void DBConn::beginTxn() {
    return;
}

void DBConn::endTxn() {
    return;
}

void DBConn::execSql(std::string& sql) {
    return;
}

void SimpleTxnLog::addTxn(const std::string& id, const std::string& sql) {
    std::set<std::string>* pSet = log_[id];
    if (pSet == nullptr) {
        pSet = new std::set<std::string>();
        log_[id] = pSet;
    }
    pSet->insert(sql);
}

void SimpleTxnLog::apply() {
    for (std::map<std::string, std::set<std::string>*>::iterator p = log_.begin(); p != log_.end(); ++p) {
        conn_->beginTxn();

        for (std::set<std::string>::iterator pSql = p->second->begin(); pSql != p->second->end(); ++pSql) {
            std::string s = *pSql;
            conn_->execSql(s);
            std::cout << "Executing SQL: " << s << std::endl;
        }

        conn_->endTxn();
        delete p->second;
    }
    log_.clear();
}

void SimpleTxnLog::purge() {
    for (auto ctr : log_)
        delete ctr.second;

    log_.clear();
}
