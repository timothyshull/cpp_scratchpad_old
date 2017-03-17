//
// Created by Timothy Shull on 12/20/15.
//

#include "6_6_2.h"
#include <iostream>
#include <map>

const std::string& Person::getFirstName() const {
    return firstName_;
}

void Person::setFirstName(const std::string& firstName_) {
    Person::firstName_ = firstName_;
}

const std::string& Person::getLastName() const {
    return lastName_;
}

void Person::setLastName(const std::string& lastName_) {
    Person::lastName_ = lastName_;
}

bool PersonLessThan::operator()(const Person& per1, const Person& per2) const {
    if (per1.lastName_ < per2.lastName_)
        return true;
    else if (per1.lastName_ == per2.lastName_)
        return per1.firstName_ < per2.firstName_;
    else
        return false;
}

void useSortingFunctor() {
    std::map<Person, std::string, PersonLessThan> personMap;

    Person per1{"Billy", "Silly"};
    Person per2{"Johnny", "Goofball"};
    Person per3{"Frank", "Stank"};
    Person per4{"Albert", "Goofball"};

    personMap[per1] = "cool";
    personMap[per2] = "not cool";
    personMap[per3] = "not cool";
    personMap[per4] = "cool";

    for (auto s : personMap)
        std::cout << s.first.getFirstName() << " " << s.first.getLastName() << " is " << s.second << std::endl;
}
