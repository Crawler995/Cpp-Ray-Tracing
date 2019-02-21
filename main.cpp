#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include "libs/vector3.h"
#include "libs/ray3.h"
#include "libs/sphere.h"
#include "libs/intersect_result.h"
#include "libs/perspective_camera.h"
#include "libs/geometry_union.h"
#include "libs/color.h"
#include "utils/utils.h"

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_DEPTH 2000
#define SAMPLE_TIMES 50


int main(int argc, char const *argv[])
{   
    PerspectiveCamera camera(
        1000, 
        Vector3(-WIDTH / 2, -HEIGHT / 2, -1000),
        Vector3(WIDTH, 0, 0),
        Vector3(0, HEIGHT, 0),
        Vector3(0, 0, 0)
    );

    GeometryUnion geometry_union(3,
        Sphere(Vector3(0, 150, -1400), 200),
        Sphere(Vector3(200, 350, -1700), 400),
        Sphere(Vector3(0, -10000, -1900), 10000)
    );
    
    FILE *f = fopen("test.ppm", "wb");
    if(!f) {
        std::cout << "Create file failed, please try again." << std::endl;
    }
    else {
        fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

        int index = 0;
        int two_percent_num = WIDTH * HEIGHT / 50;

        clock_t start, end;
        start = clock();

        std::string progress_char;
        std::cout << "Start rendering..." << std::endl;

        for(int i = HEIGHT - 1; i >= 0; i--) {
            for(int j = 0; j < WIDTH; j++) {
                Vector3 col(0, 0, 0);

                for(int k = 0; k < SAMPLE_TIMES; k++) {
                    double u = 1.0 * (j + rand_num_0_to_1()) / WIDTH;
                    double v = 1.0 * (i + rand_num_0_to_1()) / HEIGHT;

                    Ray3 ray = camera.generate_ray(u, v);
                    IntersectResult res = geometry_union.intersect(ray);

                    col = col.add(res.normal.add(Vector3(1, 1, 1)).scale(127.5));
                }

                col = col.divide(SAMPLE_TIMES);
                Color color((int)col.get_x(), (int)col.get_y(), (int)col.get_z());

                fprintf(f, "%d %d %d\n", color.get_r(), color.get_g(), color.get_b());

                index++;
                if(index % two_percent_num == 0) {
                    update_progress(progress_char);
                }
            }
        }

        end = clock();
        double run_time = (double)(end - start) / CLOCKS_PER_SEC;

        std::cout << std::endl << "Render done! Spend " << run_time << "s." << std::endl;

        fclose(f);
    }

    return 0;
}