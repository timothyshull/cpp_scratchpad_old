#ifndef SIMPLE_EVENT_SYSTEM_OBSERVERS_H
#define SIMPLE_EVENT_SYSTEM_OBSERVERS_H

#include "details.h"
#include "observer.h"
#include "subject.h"

#include <list>
#include <algorithm>

namespace Vlinder {
    namespace Observers {
        namespace Details {
            template<typename T>
            struct List : std::list<T> {};
        }
        template<
                typename Event,
                bool mt__,
                template<class> class Container = Details::List>
        class Observers
                : public Observer<Event>, public Subject<Event> {
        public :
            typedef typename Subject<Event>::ObserverType ObserverType;

            Observers() { /* no-op */ }

            ~Observers() { /* no-op */ }

            virtual void attach(ObserverType* observer)/* = 0*/
            {
                ScopedLockType lock(lock_);
                (void) lock;
                observers_.push_back(observer);
            }

            virtual void detach(ObserverType* observer)/* = 0*/
            {
                using std::find;
                ScopedLockType lock(lock_);
                (void) lock;
                Iterator which(std::find(observers_.begin(), observers_.end(), observer));
                if (which != observers_.end()) {
                    observers_.erase(which);
                } else { /* not found - not a problem */ }
            }

        protected :
            virtual void update_(const Event& event)/* = 0*/
            {
                ScopedLockType lock(lock_);
                (void) lock;
                for (
                        Iterator curr(observers_.begin());
                        curr != observers_.end();
                        ++curr) {
                    (*curr)->update(event);
                }
            }

        private :
            typedef Container<ObserverType*> ContainerType;
            typedef typename ContainerType::iterator Iterator;
            typedef typename Details::GetLockType<mt__>::type LockType;
            typedef typename Details::GetLockType<mt__>::scoped_type ScopedLockType;

            ContainerType observers_;
            LockType lock_;
        };
    }
}

#endif // SIMPLE_EVENT_SYSTEM_OBSERVERS_H
