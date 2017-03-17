#include "MazeFactory.h"
#include "MazeGame.h"
#include "Door.h"
#include "Wall.h"

namespace design_patterns {
    using std::make_shared;
    using std::make_unique;
    using room_pointer = shared_ptr<Room>;
    using door_pointer = shared_ptr<Door>;
    using maze_pointer = unique_ptr<Maze>;

    MazeGame::maze_pointer MazeGame::create_maze() {
        maze_pointer a_maze = make_unique<Maze>();
        room_pointer r1 = make_shared<Room>(1);
        room_pointer r2 = make_shared<Room>(2);

        door_pointer the_door = make_shared<Door>(r1, r2);

        a_maze->add_room(r1);
        a_maze->add_room(r2);

        r1->set_side(Direction::North, make_shared<Wall>());
        r1->set_side(Direction::South, the_door);
        r1->set_side(Direction::East, make_shared<Wall>());
        r1->set_side(Direction::West, make_shared<Wall>());

        r2->set_side(Direction::North, make_shared<Wall>());
        r2->set_side(Direction::South, make_shared<Wall>());
        r2->set_side(Direction::East, make_shared<Wall>());
        r2->set_side(Direction::West, the_door);

        return a_maze;
    }


    maze_pointer MazeGame::create_maze(MazeFactory &factory) {
        maze_pointer a_maze = factory.make_maze();
        room_pointer r1 = factory.make_room(1);
        room_pointer r2 = factory.make_room(2);

        door_pointer the_door = factory.make_door(r1, r2);

        a_maze->add_room(r1);
        a_maze->add_room(r2);

        r1->set_side(Direction::North, factory.make_wall());
        r1->set_side(Direction::South, the_door);
        r1->set_side(Direction::East, factory.make_wall());
        r1->set_side(Direction::West, factory.make_wall());

        r2->set_side(Direction::North, factory.make_wall());
        r2->set_side(Direction::South, factory.make_wall());
        r2->set_side(Direction::East, factory.make_wall());
        r2->set_side(Direction::West, the_door);

        return a_maze;
    }

}
