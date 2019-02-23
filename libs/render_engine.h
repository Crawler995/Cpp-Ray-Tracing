#ifndef RENDER_ENGINE__
#define RENDER_ENGINE__

#include <iostream>
#include "perspective_camera.h"
#include "ray3.h"
#include "geometry_union.h"
#include "color.h"

class RenderEngine {
    public:
        RenderEngine(int w, int h, int st, int rt);
        Color ray_tracing_recursive(Ray3 ray, GeometryUnion &geo_union, int reflect_times);
        void render(
            PerspectiveCamera &camera,
            GeometryUnion &geo_union,
            FILE *f,
            unsigned char *output_img_data
        );

    private:
        int image_width, image_height, sample_times, max_reflect_times;
};

#endif