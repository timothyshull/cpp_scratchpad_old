#include "util.h"

namespace paramicho {
    ClosingContextManager ClosingContextManager::enter() { return *this; }

    void ClosingContextManager::exit() {
        this->close();
    }
}