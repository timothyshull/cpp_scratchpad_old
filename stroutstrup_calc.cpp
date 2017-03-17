//
//  main.cpp
//  stroustroup_calculator
//
//  Created by Tim Shull on 10/5/16.
//  Copyright © 2016 Tim Shull. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <map>
#include <vector>

std::vector<std::string> arguments(int argc, char* argv[]);

void calculate();

double error(const std::string& s);

enum class Kind : char {
    name,
    number,
    end,
    plus = '+',
    minus = '-',
    mul = '*',
    div = '/',
    print = ';',
    assign = '=',
    lp = '(',
    rp = ')'
};

struct Token {
    Kind kind;
    std::string string_value;
    double number_value;
};

class Token_stream {
public:
    Token_stream(std::istream& s) : _input{&s}, _owns{false} {}

    Token_stream(std::istream* p) : _input{p}, _owns{true} {}

    ~Token_stream() { _close(); }

    Token get()
    {
        char ch = 0;
        // *ip >> ch;
        do { // skip whitespace except '\n'
            if (!_input->get(ch)) { return _ct = {Kind::end}; }
        } while (ch != '\n' && isspace(ch));

        switch (ch) {
            case '\0':
                return _ct = {Kind::end};
                // assign and return
            case ';':
            case '*':
            case '/':
            case '+':
            case '-':
            case '(':
            case ')':
            case '=':
                return _ct = {static_cast<Kind>(ch)};
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                _input->putback(ch); // put the first digit (or .) back into the input stream
                *_input >> _ct.number_value; // read number into ct
                _ct.kind = Kind::number;
                return _ct;
            default: // name, name =, or error
                if (std::isalpha(ch)) {
                    _ct.string_value = ch;
                    while (_input->get(ch) && isalnum(ch)) {
                        _ct.string_value += ch;
                    } // append ch to end of string_value
                    _input->putback(ch);
                    return _ct = {Kind::name};
                }
                // error("bad token");
                return _ct = {Kind::print};
        }
    }

    inline Token& current() noexcept { return _ct; };

    void set_input(std::istream& s)
    {
        _close();
        _input = &s;
        _owns = false;
    }

    void set_input(std::istream* p)
    {
        _close();
        _input = p;
        _owns = true;
    }

private:
    void _close() { if (_owns) { delete _input; }}

    std::istream* _input;
    bool _owns;
    Token _ct{Kind::end};
};

double expr(bool get);

double term(bool get);

double prim(bool get);

int no_of_errors;

std::map<std::string, double> table;

Token_stream ts{std::cin}; // use input from cin

int main(int argc, char* argv[])
{
    std::vector<std::string> args = arguments(argc, argv);
    switch (argc) {
        case 1:
            break;
        case 2:
            ts.set_input(new std::istringstream{args.at(1)});
            break;
        default:
            error("too many arguments");
            return 1;
    }

    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
    calculate();
    return no_of_errors;
}

std::vector<std::string> arguments(int argc, char* argv[])
{
    std::vector<std::string> res;
    for (int i{0}; i != argc; ++i) {
        res.emplace_back(argv[i]);
    }
    return res;
}

void calculate()
{
    for (;;) {
        ts.get();
        if (ts.current().kind == Kind::end) { break; }
        if (ts.current().kind == Kind::print) { continue; }
        std::cout << expr(false) << '\n';
    }
}

double error(const std::string& s)
{
    ++no_of_errors;
    std::cerr << "error: " << s << '\n';
    return 1;
}

double expr(bool get)
{
    double left = term(get);
    for (;;) {
        switch (ts.current().kind) {
            case
                Kind::plus:
                left += term(true);
                break;
            case
                Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}

double term(bool get)
{
    double left = prim(get);
    for (;;) {
        switch (ts.current().kind) {
            case Kind::mul:
                left *= prim(true);
                break;
            case Kind::div:
                if (auto d = prim(true)) {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}

double prim(bool get)
{
    if (get) { ts.get(); } // read next token
    switch (ts.current().kind) {
        case Kind::number: {
            double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name: {
            double& v = table[ts.current().string_value];
            if (ts.get().kind == Kind::assign) { v = expr(true); }
            return v;
        }
        case Kind::minus:
            return -prim(true);
        case Kind::lp: {
            auto e = expr(true);
            if (ts.current().kind != Kind::rp) { return error("')' expected"); }
            ts.get(); // eat ’)’
            return e;
        }
        default:
            return error("primary expected");
    }
}
