#ifndef GEOMETRY__
#define GEOMETRY__

#include "phong_material.h"
#include "intersect_result.h"
#include "ray3.h"

class Geometry {
    public:
        PhongMaterial get_material() {
            return material;
        }

        void set_material(PhongMaterial material) {
            this -> material = material;
        }

        virtual IntersectResult intersect(Ray3 ray) {
            return IntersectResult(0, 0, Vector3(0, 0, 0), Vector3(0, 0, 0));
        }
    private:
        PhongMaterial material;
};

#endif