//
// Created by Timothy Shull on 12/31/15.
//

#ifndef CPP_COOKBOOK_10_4_H
#define CPP_COOKBOOK_10_4_H

#include <iostream>
#include <string>

class Employer {
    friend std::ostream& operator<<(std::ostream&, Employer&);

public:
    Employer() { }

    ~Employer() { }

    void setName(const std::string&);

private:
    std::string name_;
};

class Employee {
    friend std::ostream& operator<<(std::ostream&, Employee&);
    friend std::istream& operator>>(std::istream&, Employee&);

public:
    Employee() : empr_(nullptr) { }

    ~Employee();

    void setFirstName(const std::string&);

    void setLastName(const std::string&);

    void setEmployer(Employer&);

    const Employer* getEmployer() const;

private:
    std::string firstName_;
    std::string lastName_;
    Employer* empr_;
};

void testPrintToStream();

void testReadFromStream();

#endif //CPP_COOKBOOK_10_4_H
