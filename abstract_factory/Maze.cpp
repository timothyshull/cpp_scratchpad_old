#include "Maze.h"

namespace design_patterns {

    Maze::Maze() { }

    void Maze::add_room(room_pointer rm) {
        rooms_.push_back(rm);
    }

    room_pointer Maze::room_no(int rm_no) const {
        try {
            return rooms_.at(static_cast<size_t>(rm_no));
        } catch (std::out_of_range e1) {
            return nullptr;
        }
    }

}
