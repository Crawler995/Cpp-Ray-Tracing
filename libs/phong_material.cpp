#include "phong_material.h"
#include "vector3.h"
#include "ray3.h"
#include "color.h"
#include <cmath>

PhongMaterial::PhongMaterial(double a, double d, double s, double h, Color a_c, Color d_c, Color s_c) {
    envir_factor = a;
    diffuse_factor = d;
    specular_factor = s;
    highlight_factor = h;

    envir_color = a_c;
    diffuse_color = d_c;
    specular_color = s_c;
}

PhongMaterial::PhongMaterial() {
    envir_factor = 0;
    diffuse_factor = specular_factor = 0.5;
    highlight_factor = 5;

    envir_color = Color(0, 0, 0);
    diffuse_color = specular_color = Color(255, 255, 255);
}

Color PhongMaterial::sample(Ray3 ray, Vector3 position, Vector3 normal) {
    Vector3 light(1, 1, 1);
    double ed = normal.dot(light.normalize());
    Vector3 h = light.normalize().subtract(ray.get_dir()).normalize();
    double es = normal.dot(h);

    ed = (ed >= 0.0) ? ed : 0;
    es = (es >= 0.0) ? es : 0;
    
    Color diffuse = diffuse_color.multiply(diffuse_factor * ed);
    Color specular = specular_color.multiply(specular_factor * pow(es, highlight_factor));
    Color envir = envir_color.multiply(envir_factor);

    Color res = envir.add(specular.add(diffuse));

    return res;
}

Color PhongMaterial::get_diffuse_color() {
    return diffuse_color;
}

void PhongMaterial::set_diffuse_color(Color c) {
    diffuse_color = c;
}
