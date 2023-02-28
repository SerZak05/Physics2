#include "object.h"
#include "merrors.h"

int Object::nextId = 0;

Object::Object(double mass) : mass(mass), pos(), vel(), id(nextId++) {
}

Object::Object(double mass, const Vector& pos) : mass(mass), pos(pos), vel(), id(nextId++) {}

Object::Object(const Object& other) : mass(other.mass), pos(other.pos), vel(other.vel), id(nextId++) {}

void Object::update(double delta) {
    // Drag
    applyForce(-vel * 0.1);
    // Gravity
    applyForce(Vector(0, 0.1));

    vel += force / mass * delta;
    force = Vector();

    pos += vel;

    mErrorLog::stream << pos << std::endl;
}

void Object::applyForce(const Vector& f) {
    force += f;
}

void Object::draw(Drawer* d) const {
    d->setColor(200, 0, 0);
    d->drawRect(pos - Vector(5, 5), pos + Vector(5, 5));
}

bool Object::operator==(const Object& other) {
    return id == other.id;
}

bool Object::operator!=(const Object& other) {
    return !(*this == other);
}
