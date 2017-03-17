//
// Created by Tim Shull on 10/15/16.
// Copyright (c) 2016 Tim Shull. All rights reserved.
//

#ifndef GAME_DEV_DESIGN_PATTERNS_COMMAND_H
#define GAME_DEV_DESIGN_PATTERNS_COMMAND_H

class Button {
    friend bool isPressed(Button *);

private:
    bool pressed_{false};
};

bool isPressed(Button *b) {
    return b->pressed_;
}

Button *BUTTON_X;
Button *BUTTON_Y;
Button *BUTTON_A;
Button *BUTTON_B;

class Command {
public:
    virtual ~Command() {
    }

    virtual void execute() = 0;

    virtual void undo() = 0;
};

class Unit {
public:
    void moveTo(int x, int y) {
        x_ = x;
        y_ = y;
    };

    int x() {
        return x_;
    };

    int y() {
        return y_;
    };

private:
    int x_;
    int y_;
};

class InputHandler {
public:
    Command *handleInput();

    // Methods to bind commands...

private:
    Command *buttonX_;
    Command *buttonY_;
    Command *buttonA_;
    Command *buttonB_;
};

Command *InputHandler::handleInput() {
    if (isPressed(BUTTON_X)) return buttonX_;
    if (isPressed(BUTTON_Y)) return buttonY_;
    if (isPressed(BUTTON_A)) return buttonA_;
    if (isPressed(BUTTON_B)) return buttonB_;

    // Nothing pressed, so do nothing.
    return nullptr;
}

class MoveUnitCommand : public Command {
public:
    MoveUnitCommand(Unit *unit, int x, int y) : unit_(unit), xBefore_(0), yBefore_(0), x_(x), y_(y) {
    }

    virtual void execute() {
        // Remember the unit's position before the move
        // so we can restore it.
        xBefore_ = unit_->x();
        yBefore_ = unit_->y();

        unit_->moveTo(x_, y_);
    }

    virtual void undo() {
        unit_->moveTo(xBefore_, yBefore_);
    }

private:
    Unit *unit_;
    int xBefore_, yBefore_;
    int x_, y_;
};

#endif //GAME_DEV_DESIGN_PATTERNS_COMMAND_H
