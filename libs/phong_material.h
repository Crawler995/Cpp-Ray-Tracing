#ifndef PHONG_MATERIAL__
#define PHONG_MATERIAL__

#include "vector3.h"
#include "ray3.h"
#include "color.h"
#include "material.h"

class PhongMaterial: public Material{
    public:
        PhongMaterial(double a, double d, double s, double h, Color a_c, Color d_c, Color s_c);
        PhongMaterial();
        Color sample(Ray3 ray, Vector3 position, Vector3 normal);

        double get_highlight_factor();

        void set_highlight_factor(double highlight_factor);
    private:
        double highlight_factor;
};

#endif