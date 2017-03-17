#ifndef SIMPLE_EVENT_SYSTEM_DETAILS_H
#define SIMPLE_EVENT_SYSTEM_DETAILS_H

#include <mutex>

namespace Vlinder {
    namespace Observers {
        namespace Details {
            template<bool mt__>
            struct GetLockType {
                typedef std::mutex type;
                typedef std::lock_guard scoped_type;
            };

            template<>
            struct GetLockType<false> {
                typedef int type;
                typedef int scoped_type;
            };
        }
    }
}

#endif // SIMPLE_EVENT_SYSTEM_DETAILS_H
