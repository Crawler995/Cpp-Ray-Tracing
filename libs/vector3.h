#ifndef VECTOR3__
#define VECTOR3__

class Vector3 {
    public:
        Vector3(double a, double b, double c);
        Vector3();
        Vector3 copy();
        double length();
        double square_length();
        Vector3 normalize();
        Vector3 negate();
        Vector3 add(Vector3 v);
        Vector3 subtract(Vector3 v);
        Vector3 scale(double a);
        Vector3 divide(double a);
        double dot(Vector3 v);
        Vector3 cross(Vector3 v);

        double get_x();
        double get_y();
        double get_z();

        void set_x(double a);
        void set_y(double a);
        void set_z(double a);
    private:
        double x, y, z;
};

#endif