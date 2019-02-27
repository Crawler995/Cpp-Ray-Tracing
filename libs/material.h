#ifndef MATERIAL__
#define MATERIAL__

#include "color.h"
#include "ray3.h"
#include "vector3.h"

class Material {
    public:
        virtual Color sample(Ray3 ray, Vector3 position, Vector3 normal);

        double get_envir_factor();
        double get_diffuse_factor();
        double get_specular_factor();
        Color get_envir_color();
        Color get_diffuse_color();
        Color get_specular_color();

        void set_envir_factor(double a);
        void set_diffuse_factor(double a);
        void set_specular_factor(double a);
        void set_envir_color(Color c);
        void set_diffuse_color(Color c);
        void set_specular_color(Color c);
    protected:
        double envir_factor, diffuse_factor, specular_factor;
        Color envir_color, diffuse_color, specular_color;
};

#endif