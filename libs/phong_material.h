#ifndef PHONG_MATERIAL__
#define PHONG_MATERIAL__

#include "vector3.h"
#include "ray3.h"
#include "color.h"

class PhongMaterial {
    public:
        PhongMaterial(double a, double d, double s, double h, Color a_c, Color d_c, Color s_c);
        PhongMaterial();
        Color sample(Ray3 ray, Vector3 normal);

        double get_envir_factor();
        double get_diffuse_factor();
        double get_specular_factor();
        double get_highlight_factor();
        Color get_envir_color();
        Color get_diffuse_color();
        Color get_specular_color();

        void set_envir_factor(double a);
        void set_diffuse_factor(double a);
        void set_specular_factor(double a);
        void set_highlight_factor(double a);
        void set_envir_color(Color c);
        void set_diffuse_color(Color c);
        void set_specular_color(Color c);
    private:
        double envir_factor, diffuse_factor, specular_factor, highlight_factor;
        Color envir_color, diffuse_color, specular_color;
};

#endif