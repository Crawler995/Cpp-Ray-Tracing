#include "checker_material.h"
#include "color.h"
#include "vector3.h"
#include "ray3.h"
#include "material.h"
#include <cmath>

CheckMaterial::CheckMaterial(double sc, double a, double d, double s, double h, Color a_c, Color s_c) {
    scale = sc;
    envir_factor = a;
    diffuse_factor = d;
    specular_factor = s;
    highlight_factor = h;
    envir_color = a_c;
    specular_color = s_c;
}

Color CheckMaterial::sample(Ray3 ray, Vector3 position, Vector3 normal) {
    Vector3 light(1, 1, 1);
    double ed = normal.dot(light.normalize());
    Vector3 h = light.normalize().subtract(ray.get_dir()).normalize();
    double es = normal.dot(h);

    ed = (ed >= 0.0) ? ed : 0;
    es = (es >= 0.0) ? es : 0;
    
    Color diffuse_color = abs(floor(position.get_x() * scale) + floor(position.get_z() * scale)) % 2 ?
                          Color(0, 0, 0) : Color(255, 255, 255);
    // Color diffuse_color(255, 255, 255);
    Color diffuse = diffuse_color.multiply(diffuse_factor * ed);
    Color specular = specular_color.multiply(specular_factor * pow(es, highlight_factor));
    Color envir = envir_color.multiply(envir_factor);

    Color res = envir.add(specular.add(diffuse));

    return res;
}

double CheckMaterial::get_scale() {
    return scale;
}

double CheckMaterial::get_highlight_factor() {
    return highlight_factor;
}

void CheckMaterial::set_scale(double a) {
    scale = a;
}

void CheckMaterial::set_highlight_factor(double highlight_factor) {
    this -> highlight_factor = highlight_factor;
}