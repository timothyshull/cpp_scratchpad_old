#ifndef JS_PROMISES_EXCEPTIONS_H
#define JS_PROMISES_EXCEPTIONS_H

#include<exception>
#include<stdexcept>
#include<string>

class Type_error : public std::exception {
private:
    std::string _imp;
public:
    explicit Type_error(const std::string &);

    explicit Type_error(const char *);

    Type_error(const Type_error &) noexcept;

    Type_error &operator=(const Type_error &) noexcept;

    virtual ~Type_error() noexcept;

    virtual const char *what() const noexcept;
};

#endif //JS_PROMISES_EXCEPTIONS_H
