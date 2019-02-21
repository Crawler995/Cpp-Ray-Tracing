#ifndef GEOMETRY_UNION__
#define GEOMETRY_UNION__

#include <vector>
#include "sphere.h"
#include "intersect_result.h"
#include "ray3.h"

class GeometryUnion {
    public:
        GeometryUnion(int count, ...);
        void add(Sphere s);
        IntersectResult intersect(Ray3 ray);
    private:
        std::vector<Sphere> geometries;
};

#endif