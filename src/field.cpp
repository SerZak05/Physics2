#include "field.h"
#include "merrors.h"

Field::Field() {
    objects.push_back(Object(1, Vector(100.0, 100.0)));
    objects.push_back(Object(1, Vector(102.0, 100.0)));

    // lastUpdate = Clock::now();
}

void Field::physUpdate() {
    updateCollisions();

    /*auto now = Clock::now();
    auto deltaDuration = now - lastUpdate;
    double delta = deltaDuration.count() / 1e6; // in milliseconds
    mErrorLog::stream << "delta=" << delta << std::endl;*/
    updateObjects(1);

    // lastUpdate = Clock::now();
}

void Field::draw(Drawer* d) const {
    for (const Object& obj : objects)
        obj.draw(d);
}

void Field::updateCollisions() {
    for (Object& obj : objects) {
        for (const Object& other : objects) {
            if (obj == other) continue;
            double radiusSq = 25;

            double distSq = (obj.getPos() - other.getPos()).squared_length();
            if (distSq < radiusSq) {
                Vector f = (obj.getPos() - other.getPos()) / sqrt(distSq);

                obj.applyForce(f);
            }
        }
    }
}

void Field::updateObjects(double delta) {
    for (Object& obj : objects)
        obj.update(delta);
}
