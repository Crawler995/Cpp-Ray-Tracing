#include "plane.h"
#include "vector3.h"
#include "ray3.h"
#include "phong_material.h"
#include "intersect_result.h"
#include <iostream>
Plane::Plane(Vector3 normal, Vector3 position, PhongMaterial material) {
    this -> normal = normal;
    this -> position = position;
    this -> set_material(material);
}

Plane Plane::copy() {
    return Plane(normal.copy(), position.copy(), get_material());
}

IntersectResult Plane::intersect(Ray3 ray) {
    IntersectResult res(0, 0, Vector3(0, 0, 0), Vector3(0, 0, 0));
    double a = ray.get_dir().dot(normal);

    if(a == 0) {
        return res;
    }

    double dis = (normal.dot(position) - normal.dot(ray.get_origin())) / a;

    if(dis < 0) {
        return res;
    }

    res.geometry = this;
    res.distance = dis;
    res.position = ray.get_point(res.distance);
    res.normal = normal;

    return res;
}

Vector3 Plane::get_normal() {
    return normal;
}

Vector3 Plane::get_position() {
    return position;
}

void Plane::set_normal(Vector3 normal) {
    this -> normal = normal;
}

void Plane::set_position(Vector3 position) {
    this -> position = position;
}