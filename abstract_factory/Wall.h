#ifndef DESIGN_PATTERNS_WALL_H
#define DESIGN_PATTERNS_WALL_H

#include "MapSite.h"

namespace design_patterns {
    class Wall : public MapSite {
    public:
        Wall();

        virtual void enter();
    };
}

#endif //DESIGN_PATTERNS_WALL_H
