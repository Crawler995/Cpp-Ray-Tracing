#ifndef PERSPECTIVE_CAMERA__
#define PERSPECTIVE_CAMERA__

#include "vector3.h"
#include "ray3.h"

class PerspectiveCamera {
    public:
        PerspectiveCamera(double d, Vector3 lb, Vector3 h, Vector3 v, Vector3 p);
        Ray3 generate_ray(double u, double v);

        double get_distance();
        Vector3 get_left_bottom_pos();
        Vector3 get_horizontal();
        Vector3 get_vertical();
        Vector3 get_camera_pos();

        void set_distance(double d);
        void set_left_bottom_pos(Vector3 lb);
        void set_horizontal(Vector3 h);
        void set_vertical(Vector3 v);
        void set_camera_pos(Vector3 p);
    private:
        double distance;
        Vector3 left_bottom_pos, horizontal, vertical, camera_pos;
};

#endif