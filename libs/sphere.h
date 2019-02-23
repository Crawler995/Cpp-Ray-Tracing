#ifndef SPHERE__
#define SPHERE__

#include "vector3.h"
#include "ray3.h"
#include "intersect_result.h"
#include "color.h"
#include "phong_material.h"
#include "geometry.h"

class Sphere: public Geometry {
    public:
        Sphere(Vector3 c, double r, PhongMaterial m);
        Sphere();
        Sphere copy();
        IntersectResult intersect(Ray3 ray);

        Vector3 get_center();
        double get_radius();

        void set_center(Vector3 c);
        void set_radius(double r);
    private:
        Vector3 center;
        double radius;
};
#endif