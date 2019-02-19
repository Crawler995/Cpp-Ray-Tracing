#ifndef RAY3__
#define RAY3__

#include "vector3.h"

class Ray3 {
    public:
        Ray3(Vector3 o, Vector3 d);
        Vector3 get_point(double t);

        Vector3 get_origin();
        Vector3 get_dir();

        void set_origin(Vector3 o);
        void set_dir(Vector3 d);
    private:
        Vector3 origin, dir;
};

#endif