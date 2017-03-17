//
// Created by Tim Shull on 10/15/16.
// Copyright (c) 2016 Tim Shull. All rights reserved.
//

#ifndef GAME_DEV_DESIGN_PATTERNS_OBSERVER_H
#define GAME_DEV_DESIGN_PATTERNS_OBSERVER_H


class Entity {
public:
    void accelerate(int force);

    void update();

    bool isOnSurface();

    bool isHero() const;
};

void Entity::accelerate(int force) {
}

void Entity::update() {
}

bool Entity::isOnSurface() {
    return true;
}

bool Entity::isHero() const {
    return true;
}

class Event {
};

class Observer {
public:
    virtual ~Observer() {
    }

    virtual void onNotify(const Entity &entity, Event event) = 0;
};


enum class EntityEvents : int {
    EVENT_ENTITY_FELL
};


class Achievements : public Observer {
public:
    virtual void onNotify(const Entity &entity, Event event) {
        switch (event) {
            case EntityEvents::EVENT_ENTITY_FELL:
                if (entity.isHero() && heroIsOnBridge_) {
                    unlock(ACHIEVEMENT_FELL_OFF_BRIDGE);
                }
                break;

                // Handle other events, and update heroIsOnBridge_...
        }
    }

private:
    void unlock(Achievement achievement) {
        // Unlock if not already unlocked...
    }

    bool heroIsOnBridge_;
};


// Changes from array to linked list
class Subject {
public:
    void addObserver(Observer *observer) {
        // Add to array...
    }

    void removeObserver(Observer *observer);

    // Other stuff...
protected:
    void notify(const Entity &entity, Event event);

private:
    static const int MAX_OBSERVERS{650};
    Observer *observers_[MAX_OBSERVERS];
    int numObservers_;
};


class Physics : public Subject {
public:
    void updateEntity(Entity &entity);
};

void Physics::updateEntity(Entity &entity) {
    bool wasOnSurface = entity.isOnSurface();
    entity.accelerate(GRAVITY);
    entity.update();
    if (wasOnSurface && !entity.isOnSurface()) {
        notify(entity, EVENT_START_FALL);
    }
}

void Subject::removeObserver(Observer *observer) {
    if (head_ == observer) {
        head_ = observer->next_;
        observer->next_ = NULL;
        return;
    }

    Observer *current = head_;
    while (current != NULL) {
        if (current->next_ == observer) {
            current->next_ = observer->next_;
            observer->next_ = NULL;
            return;
        }

        current = current->next_;
    }
}

void Subject::notify(const Entity &entity, Event event) {
//    for (int i = 0; i < numObservers_; i++) {
//        observers_[i]->onNotify(entity, event);
//    }

    Observer *observer = head_;
    while (observer != NULL) {
        observer->onNotify(entity, event);
        observer = observer->next_;
    }
}

#endif //GAME_DEV_DESIGN_PATTERNS_OBSERVER_H
