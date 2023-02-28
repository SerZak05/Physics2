#pragma once

#include <list>
#include <chrono>
#include "object.h"
#include "drawer.h"

typedef std::chrono::steady_clock Clock;

class Field {
public:
    Field();

    std::list<Object> objects;

    void physUpdate();
    void draw(Drawer*) const;

private:
    void updateCollisions();
    void updateObjects(double delta);

    // Clock::time_point lastUpdate;
};