#ifndef DESIGN_PATTERNS_MAZEFACTORY_H
#define DESIGN_PATTERNS_MAZEFACTORY_H

#include <memory>
#include "Maze.h"
#include "Wall.h"
#include "Room.h"
#include "Door.h"

namespace design_patterns {
    using std::shared_ptr;
    using std::unique_ptr;

    class MazeFactory {
        using maze_pointer = unique_ptr<Maze>;
        using wall_pointer = shared_ptr<Wall>;
        using room_pointer = shared_ptr<Room>;
        using door_pointer = shared_ptr<Door>;
    public:

        MazeFactory();

        virtual maze_pointer make_maze() const;

        virtual wall_pointer make_wall() const;

        virtual room_pointer make_room(int n) const;

        virtual door_pointer make_door(room_pointer r1, room_pointer r2) const;
    };
}

#endif //DESIGN_PATTERNS_MAZEFACTORY_H
