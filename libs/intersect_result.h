#ifndef INTERSECT_RESULT__
#define INTERSECT_RESULT__

#include "vector3.h"

class Geometry;

struct IntersectResult {
    Geometry* geometry;
    double distance;
    Vector3 position, normal;

    IntersectResult(Geometry* s, double d, Vector3 pos, Vector3 nor) {
        geometry = s;
        distance = d;
        position = pos;
        normal = nor;
    }
};

#endif