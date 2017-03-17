#include "Door.h"

namespace design_patterns {

    Door::Door(Door::room_pointer rp1, Door::room_pointer rp2) : room1_{rp1}, room2_{rp2} { }

    void Door::enter() { }

    Door::room_pointer Door::other_side_from(Door::room_pointer rp) {
        if (rp == room1_) {
            return room2_;
        } else {
            return room1_;
        }
    }

    void Door::close() {
        is_open_ = false;
    }

    void Door::open() {
        is_open_ = true;
    }

    bool Door::is_open() {
        return is_open_;
    }

}
