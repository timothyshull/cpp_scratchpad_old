#include "Room.h"

namespace design_patterns {

    Room::Room(int room_no) : room_number_{room_no} { }

    site_pointer Room::get_side(Direction dir) {
        return sides_.at(static_cast<size_t>(dir));
    }

    void Room::set_side(Direction dir, site_pointer side) {
        sides_[static_cast<size_t>(dir)] = side;
    }

    void Room::enter() { }

}
