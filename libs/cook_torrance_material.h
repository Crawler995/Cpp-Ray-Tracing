#ifndef COOK_TORRANCE__
#define COOK_TORRANCE__

#include "vector3.h"
#include "ray3.h"
#include "color.h"
#include "material.h"

class CookTorranceMaterial: public Material {
    public:
        CookTorranceMaterial(
            double envir_factor,
            double diffuse_factor,
            double specular_factor,
            double fresnel_factor,
            double roughness,
            Color envir_color,
            Color diffuse_color,
            Color specular_color
        );

        Color sample(Ray3 ray, Vector3 position, Vector3 normal);

    private:
        double fresnel_factor, roughness;

        double fresnel_reflect(Ray3 ray);
        double shadow_mask(Ray3 ray, Vector3 normal);
        double normal_distribution(Ray3 ray, Vector3 normal);

        double BRDF(Ray3 ray, Vector3 normal);
};

#endif