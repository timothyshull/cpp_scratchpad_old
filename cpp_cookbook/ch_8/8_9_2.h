//
// Created by Timothy Shull on 12/25/15.
//

#ifndef CPP_COOKBOOK_8_9_2_H
#define CPP_COOKBOOK_8_9_2_H

class Person {
    virtual void eat() = 0;

    virtual void sleep() = 0;

    virtual void walk() = 0;

    virtual void jump() = 0;
};

class IAirborne {
public:
    virtual void fly() = 0;

    virtual void up() = 0;

    virtual void down() = 0;
};

class Superhero : public Person, public IAirborne {
public:
    virtual void eat();

    virtual void sleep();

    virtual void walk();

    virtual void jump();

    virtual void fly();

    virtual void up();

    virtual void down();

    virtual ~Superhero() { }
};

void testSuperHero();

#endif //CPP_COOKBOOK_8_9_2_H
