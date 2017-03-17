#include "MazeFactory.h"

namespace design_patterns {
    using std::make_shared;
    using std::make_unique;

    MazeFactory::MazeFactory() { }

    maze_pointer MazeFactory::make_maze() const {
        return make_unique<Maze>();
    }

    wall_pointer MazeFactory::make_wall() const {
        return make_shared<Wall>();
    }

    room_pointer MazeFactory::make_room(int n) const {
        return make_shared<Room>(n);
    }

    door_pointer MazeFactory::make_door(room_pointer r1, room_pointer r2) const {
        return make_shared<Door>(r1, r2);
    }


}
