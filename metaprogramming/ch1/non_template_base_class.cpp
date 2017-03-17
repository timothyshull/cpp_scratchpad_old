#include <vector>
#include <string>

template<typename T>
class InitialMyClass {
    double value_;
    std::string name_;
    std::vector<T> data_;
public:
    std::string getName() const;
};

class MyBaseClass {
protected:
    ~MyBaseClass() {}

    double value_;
    std::string name_;
public:
    std::string getName() const;
};

template<typename T>
class MyClass : MyBaseClass {
    std::vector<T> data_;
public:
    using MyBaseClass::getName;
};