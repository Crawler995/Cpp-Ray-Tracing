#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "libs/vector3.h"
#include "libs/ray3.h"
#include "libs/sphere.h"
#include "libs/plane.h"
#include "libs/geometry.h"
#include "libs/intersect_result.h"
#include "libs/perspective_camera.h"
#include "libs/geometry_union.h"
#include "libs/color.h"
#include "utils/utils.h"
#include "libs/phong_material.h"
#include "utils/svpng.inc"

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_DEPTH 2000
#define SAMPLE_TIMES 50

unsigned char output_img_data[WIDTH * HEIGHT * 3], *p = output_img_data;

int main(int argc, char const *argv[])
{   
    PerspectiveCamera camera(
        1000, 
        Vector3(-WIDTH / 2, -HEIGHT / 2, -1000),
        Vector3(WIDTH, 0, 0),
        Vector3(0, HEIGHT, 0),
        Vector3(0, 0, 0)
    );

    PhongMaterial white(
        0.2, 0.6, 0.2, 10,
        Color(255, 255, 255),
        Color(255, 255, 255),
        Color(255, 255, 255)
    );
    PhongMaterial red(
        0.2, 0.6, 0.2, 10,
        Color(255, 0, 0),
        Color(255, 0, 0),
        Color(255, 255, 255)
    );
    PhongMaterial purple(
        0.2, 0.6, 0.2, 10,
        Color(218, 33, 255),
        Color(218, 33, 255),
        Color(255, 255, 255)
    );

    Sphere sphere_1(Vector3(0, 0, -1000), 200, red);
    Sphere sphere_2(Vector3(200, 200, -1400), 400, white);
    Plane plane_1(Vector3(0, 1, 0), Vector3(0, -100, 0), purple);

    Geometry *geos[3] = {&sphere_1, &sphere_2, &plane_1};

    GeometryUnion geometry_union(3, geos);
    
    FILE *f = fopen("test.png", "wb");
    if(!f) {
        std::cout << "Create file failed, please try again." << std::endl;
    }
    else {
        int index = 0;
        int two_percent_num = WIDTH * HEIGHT / 50;

        clock_t start, end;
        start = clock();

        std::string progress_char;
        std::cout << "Start rendering..." << std::endl;

        for(int i = HEIGHT - 1; i >= 0; i--) {
            for(int j = 0; j < WIDTH; j++) {
                Color color(0, 0, 0);

                for(int k = 0; k < SAMPLE_TIMES; k++) {
                    double u = 1.0 * (j + rand_num_0_to_1()) / WIDTH;
                    double v = 1.0 * (i + rand_num_0_to_1()) / HEIGHT;

                    Ray3 ray = camera.generate_ray(u, v);
                    IntersectResult res = geometry_union.intersect(ray);

                    if(res.geometry) {
                        color = color.add(res.geometry -> get_material().sample(ray, res.normal));
                    }
                }

                color = color.multiply(1.0 / SAMPLE_TIMES);

                *p++ = (unsigned char)color.get_r();
                *p++ = (unsigned char)color.get_g();
                *p++ = (unsigned char)color.get_b();

                index++;
                if(index % two_percent_num == 0) {
                    update_progress(progress_char);
                }
            }
        }

        end = clock();
        double run_time = (double)(end - start) / CLOCKS_PER_SEC;

        std::cout << std::endl << "Render done! Spend " << run_time << "s." << std::endl;

        svpng(f, WIDTH, HEIGHT, output_img_data, 0);
        fclose(f);
    }

    return 0;
}