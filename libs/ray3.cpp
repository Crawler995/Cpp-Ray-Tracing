#include "ray3.h"
#include "vector3.h"

Ray3::Ray3(Vector3 o, Vector3 d) {
    origin = o;
    dir = d;
}

Vector3 Ray3::get_point(double t) {
    return origin.add(dir.scale(t));
}

Vector3 Ray3::get_origin() {
    return origin;
}

Vector3 Ray3::get_dir() {
    return dir;
}

void Ray3::set_origin(Vector3 o) {
    origin = o;
}

void Ray3::set_dir(Vector3 d) {
    dir = d;
}