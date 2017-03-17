#ifndef DESIGN_PATTERNS_MAZE_H
#define DESIGN_PATTERNS_MAZE_H

#include <memory>
#include <vector>
#include "Room.h"

namespace design_patterns {
    using std::shared_ptr;
    using std::vector;
    using room_pointer = shared_ptr<Room>;

    class Maze {
    public:
        Maze();

        void add_room(room_pointer);

        room_pointer room_no(int) const;

    private:
        vector<room_pointer> rooms_;
    };

}

#endif //DESIGN_PATTERNS_MAZE_H
