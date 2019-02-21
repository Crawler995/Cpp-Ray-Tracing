#include "color.h"

Color::Color(int r, int g, int b) {
    R = r;
    G = g;
    B = b;
}

Color Color::copy() {
    return Color(R, G, B);
}

Color Color::add(Color c) {
    return Color(c.R + R, c.G + G, c.B + B);
}

Color Color::multiply(int a) {
    return Color(R * a, G * a, B * a);
}

Color Color::modulate(Color c) {
    return Color(R * c.R, G * c.G, B * c.B);
}

int Color::get_r() {
    return R;
}

int Color::get_b() {
    return B;
}

int Color::get_g() {
    return G;
}

void Color::set_r(int r) {
    R = r;
}

void Color::set_g(int g) {
    G = g;
}

void Color::set_b(int b) {
    B = b;
}