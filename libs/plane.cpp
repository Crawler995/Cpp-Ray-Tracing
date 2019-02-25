#include "plane.h"
#include "vector3.h"
#include "ray3.h"
#include "material.h"
#include "intersect_result.h"
#include <iostream>

Plane::Plane(Vector3 normal, double distance, Material *material) {
    this -> normal = normal;
    this -> distance = distance;
    this -> set_material(material);
}

Plane Plane::copy() {
    return Plane(normal.copy(), distance, get_material());
}

IntersectResult Plane::intersect(Ray3 ray) {
    IntersectResult res(0, 0, Vector3(0, 0, 0), Vector3(0, 0, 0));
    double a = ray.get_dir().dot(normal);

    if(a >= 0) {
        return res;
    }

    double b = normal.dot(ray.get_origin().add(normal.scale(distance)));
    double dis = -b / a;

    res.geometry = this;
    res.distance = dis;
    res.position = ray.get_point(res.distance);
    res.normal = normal;

    return res;
}

Vector3 Plane::get_normal() {
    return normal;
}

double Plane::get_distance() {
    return distance;
}

void Plane::set_normal(Vector3 normal) {
    this -> normal = normal;
}

void Plane::set_distance(double distance) {
    this -> distance = distance;
}