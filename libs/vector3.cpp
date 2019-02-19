#include "vector3.h"
#include <cmath>

Vector3::Vector3(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
}

Vector3::Vector3() {
    x = y = z = 0;
}

Vector3 Vector3::copy() {
    Vector3 res(x, y, z);
    return res;
}

double Vector3::length() {
    return sqrt(x * x + y * y + z * z);
}

double Vector3::square_length() {
    return x * x + y * y + z * z;
}

Vector3 Vector3::normalize() {
    double len = Vector3::length();
    Vector3 res(x / len, y / len, z / len);
    return res;
}

Vector3 Vector3::negate() {
    Vector3 res(-x, -y, -z);
    return res;
}

Vector3 Vector3::add(Vector3 v) {
    Vector3 res(x + v.get_x(), y + v.get_y(), z + v.get_z());
    return res;
}

Vector3 Vector3::subtract(Vector3 v) {
    Vector3 res(x - v.get_x(), y - v.get_y(), z - v.get_z());
    return res;
}

Vector3 Vector3::scale(double a) {
    Vector3 res(x * a, y * a, z * a);
    return res;
}

Vector3 Vector3::divide(double a) {
    Vector3 res(x / a, y / a, z / a);
    return res;
}

double Vector3::dot(Vector3 v) {
    return x * v.get_x() + y * v.get_y() + z * v.get_z();
}

Vector3 Vector3::cross(Vector3 v) {
    Vector3 res(
        -z * v.get_y() + y * v.get_z(),
        z * v.get_x() - x * v.get_z(),
        -y * v.get_x() + x * v.get_y()
    );
    return res;
}

double Vector3::get_x() {
    return x;
}

double Vector3::get_y() {
    return y;
}

double Vector3::get_z() {
    return z;
}

void Vector3::set_x(double a) {
    x = a;
}

void Vector3::set_y(double a) {
    y = a;
}

void Vector3::set_z(double a) {
    z = a;
}