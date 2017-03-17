#ifndef DESIGN_PATTERNS_MAZEGAME_H
#define DESIGN_PATTERNS_MAZEGAME_H

#include <memory>
#include "Maze.h"

namespace design_patterns {
    using std::unique_ptr;

    class MazeGame {
        using maze_pointer = unique_ptr<Maze>;
    public:
        maze_pointer create_maze();

        maze_pointer create_maze(MazeFactory &);

    };

}


#endif //DESIGN_PATTERNS_MAZEGAME_H
