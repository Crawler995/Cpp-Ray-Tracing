#ifndef SPHERE__
#define SPHERE__

#include "vector3.h"
#include "ray3.h"
#include "intersect_result.h"
#include "color.h"
#include "phong_material.h"

class Sphere {
    public:
        Sphere(Vector3 c, double r, PhongMaterial m);
        Sphere();
        Sphere copy();
        IntersectResult intersect(Ray3 r);

        Vector3 get_center();
        double get_radius();
        PhongMaterial get_material();

        void set_center(Vector3 c);
        void set_radius(double r);
        void set_material(PhongMaterial m);
    private:
        Vector3 center;
        double radius;
        PhongMaterial material;
};
#endif