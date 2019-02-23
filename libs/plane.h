#ifndef PLANE__
#define PLANE__

#include "vector3.h"
#include "ray3.h"
#include "phong_material.h"
#include "geometry.h"
#include "intersect_result.h"

class Plane: public Geometry {
    public:
        Plane(Vector3 normal, Vector3 position, PhongMaterial material);
        Plane copy();
        IntersectResult intersect(Ray3 ray);

        Vector3 get_normal();
        Vector3 get_position();

        void set_normal(Vector3 normal);
        void set_position(Vector3 position);
    private:
        Vector3 normal, position;
};

#endif