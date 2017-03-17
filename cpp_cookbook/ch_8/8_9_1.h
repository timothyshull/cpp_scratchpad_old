//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_9_1_H
#define CPP_COOKBOOK_8_9_1_H

#include <string>

class AbstractConfigFile {
public:
    virtual ~AbstractConfigFile() { }

    virtual void getKey(const std::string&, const std::string&, const std::string&) const = 0;

    virtual void exists(const std::string&, const std::string&, const std::string&) const = 0;
};

class TXTConfigFile : public AbstractConfigFile {
public:
    TXTConfigFile() : in_{nullptr} { }

    TXTConfigFile(std::istream& in) : in_{&in} { }

    virtual ~TXTConfigFile() { }

    virtual void getKey(const std::string&, const std::string&, const std::string&) const { }

    virtual void exists(const std::string&, const std::string&, const std::string&) const { }

protected:
    std::istream* in_;
};

class MyAppClass {
public:
    MyAppClass() : config_{nullptr} { }

    virtual ~MyAppClass() { }

    void setConfigObj(const AbstractConfigFile*);

    void myMethod();

private:
    const AbstractConfigFile* config_;
};

void testAbstract();

#endif //CPP_COOKBOOK_8_9_1_H
