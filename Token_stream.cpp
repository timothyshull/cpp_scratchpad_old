#include <string>
#include "Token_stream.h"

using string = std::string;

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
    string string_value;
    double number_value;
};

double term(bool);

double prim(bool);

double expr(bool get) {
    double left = term(get);

    for (;;) {
        switch (ts.current().kind) {
            case Kind::plus;
                left += term(true);
                break;
            case Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}

double term(bool get) {
    double left = prim(get);

    for (;;) {
        switch (ts.current().kind) {
            case Kind::mul;
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

double prim(bool get) {
    if (get) ts.get(); // read next token
    switch (ts.current().kind) {
        case Kind::number: {
            double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name: {
            double &v = table[ts.current().string_value];
            if (ts.get().kind == Kind::assign) v = expr(true);
            return v;
        }
        case Kind::minus:
            return -1 * prim(true);
        case Kind::lp: {
            auto e = expr(true);
            if (ts.current().kind != Kind::rp) return error("')' expected");
            ts.get(); // eat ’)’
            return e;
        }
        default:
            return error("primary expected");
    }

}