#pragma once

#include <CGAL/Cartesian.h>

typedef CGAL::Cartesian<double> Ker;
typedef Ker::Vector_2 Vector;
typedef std::pair<Vector, Vector> Rect;