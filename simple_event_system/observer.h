#ifndef SIMPLE_EVENT_SYSTEM_OBSERVER_H
#define SIMPLE_EVENT_SYSTEM_OBSERVER_H

namespace Vlinder {
    namespace Observers {
        template<typename Event>
        class Observer {
        public :
            Observer() { /* no-op */ }

            virtual ~Observer() { /* no-op */ }

            void update(const Event& event) throw()
            {
                try {
                    update_(event);
                }
                catch (...) { /* observer must provide the no-fail guarantee,
               * so we enforce the guarantee, without resorting
               * to std::unexpected, which would be bad manners */ }
            }

        protected :
            virtual void update_(const Event& event) = 0;

        private :
        };
    }
}

#endif // SIMPLE_EVENT_SYSTEM_OBSERVER_H
