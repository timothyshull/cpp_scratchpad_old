#ifndef DESIGN_PATTERNS_DOOR_H
#define DESIGN_PATTERNS_DOOR_H

#include <memory>
#include "MapSite.h"
#include "Room.h"

namespace design_patterns {
    using std::shared_ptr;

    class Door : public MapSite {
        using room_pointer = shared_ptr<Room>
    public:
        Door(room_pointer = nullptr, room_pointer = nullptr);

        virtual void enter();

        room_pointer other_side_from(room_pointer);

        void close();

        void open();

        bool is_open();
    private:
        room_pointer room1_;
        room_pointer room2_;
        bool is_open_;
    };

}


#endif //DESIGN_PATTERNS_DOOR_H
