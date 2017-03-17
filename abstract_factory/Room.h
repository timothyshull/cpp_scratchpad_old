#ifndef DESIGN_PATTERNS_ROOM_H
#define DESIGN_PATTERNS_ROOM_H

#include <memory>
#include <array>
#include "MapSite.h"

namespace design_patterns {
    using std::shared_ptr;
    using std::array;
    using site_pointer = shared_ptr<MapSite>;

    class Room : public MapSite {
    public:
        Room(int room_no);

        site_pointer get_side(Direction dir);

        void set_side(Direction dir, site_pointer side);

        virtual void enter();

    private:
        int room_number_;
        array<site_pointer, 4> sides_;
    };

}

#endif //DESIGN_PATTERNS_ROOM_H
