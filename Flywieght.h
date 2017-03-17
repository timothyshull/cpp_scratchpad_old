//
// Created by Tim Shull on 10/15/16.
// Copyright (c) 2016 Tim Shull. All rights reserved.
//

#ifndef GAME_DEV_DESIGN_PATTERNS_FLYWIEGHT_H
#define GAME_DEV_DESIGN_PATTERNS_FLYWIEGHT_H

#include <random>

// Ex. 1
class Mesh {
};

class Texture {
};

class Vector {
};

class Color {
};

class TreeModel {
private:
    Mesh mesh_;
    Texture bark_;
    Texture leaves_;
};

class Tree {
private:
    TreeModel *model_;

    Vector position_;
    double height_;
    double thickness_;
    Color barkTint_;
    Color leafTint_;
};


// Ex. 2
//enum Terrain {
//    TERRAIN_GRASS,
//    TERRAIN_HILL,
//    TERRAIN_RIVER
//    // Other terrains...
//};

class Terrain {
public:
    Terrain(int movementCost, bool isWater, Texture texture)
            : movementCost_(movementCost), isWater_(isWater), texture_(texture) {
    }

    int getMovementCost() const {
        return movementCost_;
    }

    bool isWater() const {
        return isWater_;
    }

    const Texture &getTexture() const {
        return texture_;
    }

private:
    int movementCost_;
    bool isWater_;
    Texture texture_;
};

class World {
public:
    int getMovementCost(int x, int y);

    bool isWater(int x, int y);

private:
    static const int WIDTH{100};
    static const int HEIGHT{50};
    Terrain *tiles_[WIDTH][HEIGHT];
};

int World::getMovementCost(int x, int y) {
    switch (tiles_[x][y]) {
        case TERRAIN_GRASS:
            return 1;
        case TERRAIN_HILL:
            return 3;
        case TERRAIN_RIVER:
            return 2;
            // Other terrains...
    }
}

bool World::isWater(int x, int y) {
    switch (tiles_[x][y]) {
        case TERRAIN_GRASS:
            return false;
        case TERRAIN_HILL:
            return false;
        case TERRAIN_RIVER:
            return true;
            // Other terrains...
    }
}

class World {
public:
    World() : grassTerrain_(1, false, GRASS_TEXTURE),
              hillTerrain_(3, false, HILL_TEXTURE),
              riverTerrain_(2, true, RIVER_TEXTURE) {
    }

    void generateTerrain();

    const Terrain &World::getTile(int x, int y) const;

private:
    Terrain grassTerrain_;
    Terrain hillTerrain_;
    Terrain riverTerrain_;

    // Other stuff...
};

void World::generateTerrain() {
    // Fill the ground with grass.
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            // Sprinkle some hills.
            if (random(10) == 0) {
                tiles_[x][y] = &hillTerrain_;
            } else {
                tiles_[x][y] = &grassTerrain_;
            }
        }
    }

    // Lay a river.
    int x = random(WIDTH);
    for (int y = 0; y < HEIGHT; y++) {
        tiles_[x][y] = &riverTerrain_;
    }
}

const Terrain &World::getTile(int x, int y) const {
    return *tiles_[x][y];
}

#endif //GAME_DEV_DESIGN_PATTERNS_FLYWIEGHT_H
