#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "libs/vector3.h"
#include "libs/ray3.h"
#include "libs/sphere.h"
#include "libs/intersect_result.h"
#include "libs/perspective_camera.h"

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_DEPTH 500

void show_progress(int index, int two_percent_pixel_num);

int main(int argc, char const *argv[])
{   
    PerspectiveCamera camera(
        100, 
        Vector3(-WIDTH / 2, -HEIGHT / 2, -400),
        Vector3(WIDTH, 0, 0),
        Vector3(0, HEIGHT, 0),
        Vector3(0, 0, 0)
    );

    Sphere sphere(Vector3(0, 0, -400), 200);
    
    FILE *f = fopen("test.ppm", "wb");
    if(!f) {
        std::cout << "failed" << std::endl;
    }
    else {
        fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

        int index = 0;
        int two_percent_pixel_num = WIDTH * HEIGHT / 50;
        double percent = 0;

        clock_t start, end;
        start = clock();

        for(int i = HEIGHT - 1; i >= 0; i--) {
            for(int j = 0; j < WIDTH; j++) {
                double u = 1.0 * j / WIDTH;
                double v = 1.0 * i / HEIGHT;
                Ray3 ray = camera.generate_ray(u, v);
                IntersectResult res = sphere.intersect(ray);

                int distance = 255 - std::min((res.distance / MAX_DEPTH) * 255, 255.0);
                fprintf(f, "%d %d %d\n", distance, distance, distance);

                index++;
                show_progress(index, two_percent_pixel_num);
            }
        }

        end = clock();
        double run_time = (double)(end - start) / CLOCKS_PER_SEC;

        std::cout << std::endl << "Render done! Spend " << run_time << "s." << std::endl;

        fclose(f);
    }

    return 0;
}

void show_progress(int index, int two_percent_pixel_num) {
    if(index % two_percent_pixel_num == 0) {
        std::cout << "\r[";
        for(int i = 0; i < index / two_percent_pixel_num; i++) {
            std::cout << "#";
        }
        for(int i = 0; i < 50 - index / two_percent_pixel_num; i++) {
            std::cout << " ";
        }
        std::cout << "] ";
        int percent = 100.0 * index / (WIDTH * HEIGHT);
        std::cout << "[" << percent << "%]";
    }
}