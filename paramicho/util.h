#ifndef PARAMICHO_UTIL_H
#define PARAMICHO_UTIL_H

namespace paramicho {

    class ClosingContextManager {
    public:
        virtual ClosingContextManager enter();
//        def __exit__(self, type, value, traceback):
        virtual void exit();
    };
}


#endif //PARAMICHO_UTIL_H
