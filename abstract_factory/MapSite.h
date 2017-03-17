#ifndef DESIGN_PATTERNS_MAPSITE_H
#define DESIGN_PATTERNS_MAPSITE_H

namespace design_patterns {
    class MapSite {
    public:
        virtual void enter() = 0;
    };

    enum class Direction {
        North = 0, South = 1, East = 2, West = 3
    };

}

#endif //DESIGN_PATTERNS_MAPSITE_H
