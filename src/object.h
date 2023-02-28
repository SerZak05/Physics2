#pragma once
#include "geomtypedefs.h"
#include "drawer.h"


class Object {
public:
    explicit Object(double mass);
    Object(double mass, const Vector& pos);
    Object(const Object&);

    void update(double delta);
    void applyForce(const Vector& force);

    void draw(Drawer*) const;

    bool operator==(const Object&);
    bool operator!=(const Object&);

    inline double getMass() const { return mass; }
    inline Vector getPos() const { return pos; }
    inline Vector getVel() const { return vel; }

private:
    static int nextId;
    int id;

    Vector pos, vel;
    double mass;

    Vector force;
};