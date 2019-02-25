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

        Color get_diffuse_color();

        void set_diffuse_color(Color c);
    private:
        Color diffuse_color;
};

#endif