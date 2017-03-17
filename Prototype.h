//
// Created by Tim Shull on 10/15/16.
// Copyright (c) 2016 Tim Shull. All rights reserved.
//

#ifndef GAME_DEV_DESIGN_PATTERNS_PROTOTYPE_H
#define GAME_DEV_DESIGN_PATTERNS_PROTOTYPE_H


class Monster {
public:
    virtual ~Monster() {
    }

    virtual Monster *clone() = 0;
};

//class Ghost : public Monster {};
class Ghost : public Monster {
public:
    Ghost(int health, int speed)
            : health_(health),
              speed_(speed) {
    }

    virtual Monster *clone() {
        return new Ghost(health_, speed_);
    }

private:
    int health_;
    int speed_;
};

class Demon : public Monster {
};

class Sorcerer : public Monster {
};


class Spawner {
public:
    Spawner(Monster *prototype)
            : prototype_(prototype) {
    }

    Monster *spawnMonster() {
        return prototype_->clone();
    }

private:
    Monster *prototype_;
};

class GhostSpawner : public Spawner {
public:
    virtual Monster *spawnMonster() {
        return new Ghost();
    }
};

class DemonSpawner : public Spawner {
public:
    virtual Monster *spawnMonster() {
        return new Demon();
    }
};

Monster *spawnGhost() {
    return new Ghost();
}

typedef Monster *(*SpawnCallback)();

class Spawner {
public:
    Spawner(SpawnCallback spawn)
            : spawn_(spawn) {
    }

    Monster *spawnMonster() {
        return spawn_();
    }

private:
    SpawnCallback spawn_;
};

Spawner *ghostSpawner = new Spawner(spawnGhost);


class Spawner {
public:
    virtual ~Spawner() {
    }

    virtual Monster *spawnMonster() = 0;
};

template<class T>
class SpawnerFor : public Spawner {
public:
    virtual Monster *spawnMonster() {
        return new T();
    }
};

Spawner *ghostSpawner = new SpawnerFor<Ghost>();
// You get the idea...


#endif //GAME_DEV_DESIGN_PATTERNS_PROTOTYPE_H
