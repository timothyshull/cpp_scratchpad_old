//
// Created by Timothy Shull on 12/31/15.
//

#include "10_4.h"

void Employer::setName(const std::string& name) {
    name_ = name;
}


void Employee::setFirstName(const std::string& name) {
    firstName_ = name;
}


void Employee::setLastName(const std::string& name) {
    lastName_ = name;
}


void Employee::setEmployer(Employer& employer) {
    empr_ = &employer;
}


const Employer* Employee::getEmployer() const {
    return empr_;
}


std::ostream& operator<<(std::ostream& out, Employer& employer) {
    out << employer.name_ << std::endl;
    return out;
}


std::ostream& operator<<(std::ostream& out, Employee& employee) {
    out << employee.firstName_ << std::endl;
    out << employee.lastName_ << std::endl;
    if (employee.empr_)
        out << *employee.empr_ << std::endl;

    return out;
}


std::istream& operator>>(std::istream& in, Employee& employee) {
    in >> employee.firstName_;
    in >> employee.lastName_;

    return in;
}

void testPrintToStream() {
    Employee emp;
    emp.setFirstName("William");
    emp.setLastName("Shatner");

    Employer empr;
    empr.setName("Enterprise");

    std::cout << emp;
}


void testReadFromStream() {
    Employee emp;
    std::string first = "William";
    std::string last = "Shatner";
    emp.setFirstName(first);
    emp.setLastName(last);
    std::ofstream out("tmp\\emp.txt");
    if (!out) {
        std::cerr << "Unable to open output file.\ n";
        exit(EXIT_FAILURE);
    }
    out << emp; // Write the Emp to the file
    out.close();

    std::ifstream in("tmp\\emp.txt");
    if (!in) {
        std::cerr << "Unable to open input file.\ n";
        exit(EXIT_FAILURE);
    }
    Employee emp2;
    in >> emp2; // Read the file into an empty object
    in.close();
    cout << emp2;


}
