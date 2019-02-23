#ifndef GEOMETRY_UNION__
#define GEOMETRY_UNION__

#include <vector>
#include "geometry.h"
#include "intersect_result.h"
#include "ray3.h"

class GeometryUnion {
    public:
        GeometryUnion(int count, Geometry *geos[]);
        void add(Geometry *s);
        IntersectResult intersect(Ray3 ray);
    private:
        std::vector<Geometry*> geometries;
};

#endif