#include "sphere.h"
#include "vector3.h"
#include "ray3.h"
#include "intersect_result.h"
#include "color.h"
#include "phong_material.h"
#include <cmath>

Sphere::Sphere(Vector3 c, double r, PhongMaterial m) {
    center = c;
    radius = r;
    set_material(m);
}

Sphere::Sphere() {
    center = Vector3(0, 0, 0);
    radius = 0;
    set_material(PhongMaterial(0, 0, 0, 0, Color(0, 0, 0), Color(0, 0, 0), Color(0, 0, 0)));
}

Sphere Sphere::copy() {
    return Sphere(center, radius, get_material());
}

IntersectResult Sphere::intersect(Ray3 ray) {
    Vector3 v = ray.get_origin().subtract(center);
    double a = ray.get_dir().square_length();
    double b = 2 * v.dot(ray.get_dir());
    double c = v.square_length() - radius * radius;

    double delta = b * b - 4 * a * c;

    IntersectResult res(0, 0, Vector3(0, 0, 0), Vector3(0, 0, 0));
    if(delta >= 0 && b <= 0) {
        res.geometry = this;
        res.distance = (-b - sqrt(delta)) / (2 * a);
        res.position = ray.get_point(res.distance);
        res.normal = res.position.subtract(center).normalize();
    }

    return res;
}

Vector3 Sphere::get_center() {
    return center;
}

double Sphere::get_radius() {
    return radius;
}


void Sphere::set_center(Vector3 c) {
    center = c;
}

void Sphere::set_radius(double r) {
    radius = r;
}
