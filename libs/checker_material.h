#ifndef CHECKER_MATERIAL__
#define CHECKER_MATERIAL__

#include "phong_material.h"
#include "color.h"
#include "vector3.h"
#include "ray3.h"
#include "material.h"

class CheckMaterial: public Material {
    public:
        CheckMaterial(double sc, double a, double d, double s, double h, Color a_c, Color s_c);
        Color sample(Ray3 ray, Vector3 position, Vector3 normal);

        double get_scale();

        void set_scale(double a);
    private:
        double scale;
};

#endif