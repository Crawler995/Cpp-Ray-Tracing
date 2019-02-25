#ifndef PLANE__
#define PLANE__

#include "vector3.h"
#include "ray3.h"
#include "material.h"
#include "geometry.h"
#include "intersect_result.h"

class Plane: public Geometry {
    public:
        Plane(Vector3 normal, double distance, Material *material);
        Plane copy();
        IntersectResult intersect(Ray3 ray);

        Vector3 get_normal();
        double get_distance();

        void set_normal(Vector3 normal);
        void set_distance(double distance);
    private:
        Vector3 normal;
        double distance;
};

#endif