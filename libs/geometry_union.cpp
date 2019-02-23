#include <vector>
#include "geometry_union.h"
#include "geometry.h"
#include "intersect_result.h"
#include "ray3.h"

#define MAX_DISTANCE 1e7

GeometryUnion::GeometryUnion(int count, Geometry *geos[]) {
    for(int i = 0; i < count; i++) {
        geometries.push_back(geos[i]);
    }
}

void GeometryUnion::add(Geometry *s) {
    geometries.push_back(s);
}

IntersectResult GeometryUnion::intersect(Ray3 ray) {
    int size = geometries.size();
    double min_dis = MAX_DISTANCE;
    IntersectResult res(0, 0, Vector3(0, 0, 0), Vector3(0, 0, 0));
    for(int i = 0; i < size; i++) {
        IntersectResult tmp = geometries[i] -> intersect(ray);
        if(tmp.geometry && tmp.distance < min_dis) {
            min_dis = tmp.distance;
            res = tmp;
        }
    }
    return res;
}