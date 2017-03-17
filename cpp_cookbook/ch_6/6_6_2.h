//
// Created by Timothy Shull on 12/20/15.
//

#ifndef CPPCOOKBOOK_6_6_2_H
#define CPPCOOKBOOK_6_6_2_H

#include <string>

class Person {
    std::string firstName_, lastName_;

    friend class PersonLessThan;

public:
    Person(const std::string& firstName_, const std::string& lastName_) : firstName_(firstName_),
                                                                          lastName_(lastName_) { }

    const std::string& getFirstName() const;

    void setFirstName(const std::string& firstName_);

    const std::string& getLastName() const;

    void setLastName(const std::string& lastName_);
};

class PersonLessThan {
public:
    bool operator()(const Person&, const Person&) const;
};

void useSortingFunctor();

#endif //CPPCOOKBOOK_6_6_2_H
