#ifndef GEOMETRY__
#define GEOMETRY__

#include "material.h"
#include "intersect_result.h"
#include "ray3.h"

class Geometry {
    public:
        Material* get_material() {
            return material;
        }

        void set_material(Material *material) {
            this -> material = material;
        }

        virtual IntersectResult intersect(Ray3 ray) {
            return IntersectResult(0, 0, Vector3(0, 0, 0), Vector3(0, 0, 0));
        }
    private:
        Material *material;
};

#endif