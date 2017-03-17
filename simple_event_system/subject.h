#ifndef SIMPLE_EVENT_SYSTEM_SUBJECT_H
#define SIMPLE_EVENT_SYSTEM_SUBJECT_H

#include "observers.h"
#include "observer.h"

namespace Vlinder {
    namespace Observers {
        template<typename Event, typename ObserverType_ = Observer<Event>>
        class Subject {
        public :
            typedef ObserverType_ ObserverType;

            Subject() { /* no-op */ }

            virtual ~Subject() { /* no-op */ }

            virtual void attach(ObserverType* observer) = 0;

            virtual void detach(ObserverType* observer) = 0;
        };
    }
}

#endif // SIMPLE_EVENT_SYSTEM_SUBJECT_H
