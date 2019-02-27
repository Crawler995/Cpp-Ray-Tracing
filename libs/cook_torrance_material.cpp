#include "cook_torrance_material.h"
#include "vector3.h"
#include "ray3.h"
#include "color.h"
#include "material.h"
#include <cmath>
#include <algorithm>

CookTorranceMaterial::CookTorranceMaterial(
    double envir_factor,
    double diffuse_factor,
    double specular_factor,
    double fresnel_factor,
    double roughness,
    Color envir_color,
    Color diffuse_color,
    Color specular_color
) {
    this -> envir_factor = envir_factor;
    this -> diffuse_factor = diffuse_factor;
    this -> specular_factor = specular_factor;
    this -> fresnel_factor = fresnel_factor;
    this -> roughness = roughness;
    this -> envir_color = envir_color;
    this -> diffuse_color = diffuse_color;
    this -> specular_color = specular_color;
}

Color CookTorranceMaterial::sample(Ray3 ray, Vector3 position, Vector3 normal) {
    Vector3 light(1, 1, 1);
    double ed = normal.dot(light.normalize());
    Vector3 h = light.normalize().subtract(ray.get_dir()).normalize();

    ed = (ed >= 0.0) ? ed : 0;
    
    Color diffuse = diffuse_color.multiply(diffuse_factor * ed);
    Color specular = specular_color.multiply(specular_factor * BRDF(ray, normal));
    Color envir = envir_color.multiply(envir_factor);

    Color res = envir.add(specular.add(diffuse));

    return res;
}

double CookTorranceMaterial::fresnel_reflect(Ray3 ray) {
    Vector3 light(1, 1, 1);
    Vector3 h = light.normalize().subtract(ray.get_dir()).normalize();
    return fresnel_factor + (1.0 - fresnel_factor) * pow((1.0 - h.dot(ray.get_dir().negate())), 5);
}

double CookTorranceMaterial::shadow_mask(Ray3 ray, Vector3 normal) {
    Vector3 light(1, 1, 1);
    Vector3 h = light.normalize().subtract(ray.get_dir()).normalize();
    double n_dot_h = normal.dot(h);
    double a = 1.0 / (roughness * roughness * pow(n_dot_h, 4) * 4);
    double b = (n_dot_h * n_dot_h - 1) / (roughness * roughness * n_dot_h * n_dot_h);
    return a * exp(b);
}

double CookTorranceMaterial::normal_distribution(Ray3 ray, Vector3 normal) {
    Vector3 light(1, 1, 1);
    Vector3 h = light.normalize().subtract(ray.get_dir()).normalize();

    double n_dot_h = normal.dot(h);
    double v_dot_h = ray.get_dir().negate().dot(h);

    double g1 = 2 * n_dot_h * normal.dot(light.normalize()) / v_dot_h;
    double g2 = 2 * n_dot_h * normal.dot(ray.get_dir().negate()) / v_dot_h;

    return std::min(std::min(1.0, g1), g2);
}

double CookTorranceMaterial::BRDF(Ray3 ray, Vector3 normal) {
    Vector3 light(1, 1, 1);
    double F = fresnel_reflect(ray);
    double D = shadow_mask(ray, normal);
    double G = normal_distribution(ray, normal);

    double n_dot_v = normal.dot(ray.get_dir().negate());
    double n_dot_l = normal.dot(light.normalize());

    return (F * D * G) / (n_dot_v * n_dot_l * 4);
}