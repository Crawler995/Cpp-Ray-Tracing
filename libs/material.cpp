#include "material.h"
#include "color.h"

Color Material::sample(Ray3 ray, Vector3 position, Vector3 normal) {
    return Color(0, 0, 0);
}

double Material::get_envir_factor() {
    return envir_factor;
}

double Material::get_diffuse_factor() {
    return diffuse_factor;
}

double Material::get_specular_factor() {
    return specular_factor;
}

Color Material::get_envir_color() {
    return envir_color;
}

Color Material::get_diffuse_color() {
    return diffuse_color;
}

Color Material::get_specular_color() {
    return specular_color;
}

void Material::set_envir_factor(double a) {
    envir_factor = a;
}

void Material::set_diffuse_factor(double a) {
    diffuse_factor = a;
}

void Material::set_specular_factor(double a) {
    specular_factor = a;
}

void Material::set_envir_color(Color c) {
    envir_color = c;
}

void Material::set_diffuse_color(Color c) {
    diffuse_color = c;
}

void Material::set_specular_color(Color c) {
    specular_color = c;
}