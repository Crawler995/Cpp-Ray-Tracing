#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "libs/vector3.h"
#include "libs/ray3.h"
#include "libs/sphere.h"
#include "libs/intersect_result.h"
#include "libs/perspective_camera.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_DEPTH 500

int main(int argc, char const *argv[])
{   
    PerspectiveCamera camera(
        100, 
        Vector3(-WIDTH / 2, -HEIGHT / 2, -400),
        Vector3(WIDTH, 0, 0),
        Vector3(0, HEIGHT, 0),
        Vector3(0, 0, 0)
    );

    Sphere sphere(Vector3(0, 0, -400), 100);
    
    FILE *f = fopen("test.ppm", "wb");
    if(!f) {
        std::cout << "failed" << std::endl;
    }
    else {
        fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

        for(int i = HEIGHT - 1; i >= 0; i--) {
            for(int j = 0; j < WIDTH; j++) {
                double u = 1.0 * j / WIDTH;
                double v = 1.0 * i / HEIGHT;
                Ray3 ray = camera.generate_ray(u, v);
                IntersectResult res = sphere.intersect(ray);

                int distance = 255 - std::min((res.distance / MAX_DEPTH) * 255, 255.0);
                fprintf(f, "%d %d %d\n", distance, distance, distance);
            }
        }

        fclose(f);
    }
    return 0;
}