#include "perspective_camera.h"
#include "ray3.h"

PerspectiveCamera::PerspectiveCamera(double d, Vector3 lb, Vector3 h, Vector3 v, Vector3 p) {
    distance = d;
    left_bottom_pos = lb;
    horizontal = h;
    vertical = v;
    camera_pos = p;
}

Ray3 PerspectiveCamera::generate_ray(double u, double v) {
    return Ray3(
        camera_pos,
        left_bottom_pos.add(horizontal.scale(u))
                       .add(vertical.scale(v))
                       .normalize()
    );
}

double PerspectiveCamera::get_distance() {
    return distance;
}

Vector3 PerspectiveCamera::get_left_bottom_pos() {
    return left_bottom_pos;
}

Vector3 PerspectiveCamera::get_horizontal() {
    return horizontal;
}

Vector3 PerspectiveCamera::get_vertical() {
    return vertical;
}

Vector3 PerspectiveCamera::get_camera_pos() {
    return camera_pos;
}

void PerspectiveCamera::set_distance(double d) {
    distance = d;
}

void PerspectiveCamera::set_left_bottom_pos(Vector3 lb) {
    left_bottom_pos = lb;
}

void PerspectiveCamera::set_horizontal(Vector3 h) {
    horizontal = h;
}

void PerspectiveCamera::set_vertical(Vector3 v) {
    vertical = v;
}

void PerspectiveCamera::set_camera_pos(Vector3 p) {
    camera_pos = p;
}