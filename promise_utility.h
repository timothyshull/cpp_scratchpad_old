#ifndef JS_PROMISES_UTILITY_H
#define JS_PROMISES_UTILITY_H

#include <cstdlib>
#include <cstdio>

void lassert(bool x, const char *m) {
    if (!x) {
        std::fprintf(stderr, "%s\n", m);
        std::abort();
    }
}

struct Noop {
    void operator()(...) {}
};

#endif //JS_PROMISES_UTILITY_H
