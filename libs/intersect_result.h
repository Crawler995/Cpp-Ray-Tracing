#ifndef INTERSECT_RESULT__
#define INTERSECT_RESULT__

#include "vector3.h"
#include "sphere.h"

class Sphere;

struct IntersectResult {
    Sphere* geometry;
    double distance;
    Vector3 position, normal;

    IntersectResult(Sphere* s, double d, Vector3 pos, Vector3 nor) {
        geometry = s;
        distance = d;
        position = pos;
        normal = nor;
    }
};

#endif