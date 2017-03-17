#ifndef BEASTIT_IO_HANDLER_H
#define BEASTIT_IO_HANDLER_H

#include "Event_emitter.h"

class Handler {
public:
    template<typename ...Args>
    void call(Event_emitter* self, Args ...args)
    {

    }

    template<typename ...Args>
    void operator()(Event_emitter* self, Args ...args)
    {

    }
};

#endif // BEASTIT_IO_HANDLER_H
