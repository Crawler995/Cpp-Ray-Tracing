#include <iostream>
#include <cstdlib>
#include <string>
#include "libs/vector3.h"
#include "libs/sphere.h"
#include "libs/plane.h"
#include "libs/geometry.h"
#include "libs/perspective_camera.h"
#include "libs/geometry_union.h"
#include "libs/color.h"
#include "libs/phong_material.h"
#include "libs/checker_material.h"
#include "libs/render_engine.h"

#define WIDTH 1920
#define HEIGHT 1080
#define SAMPLE_TIMES 20
#define MAX_REFLECT_TIMES 20

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
        0.2, 0.6, 0.2, 50,
        Color(255, 255, 255),
        Color(255, 255, 255),
        Color(255, 255, 255)
    );
    PhongMaterial red(
        0.2, 0.6, 0.2, 50,
        Color(255, 0, 0),
        Color(255, 0, 0),
        Color(255, 255, 255)
    );
    PhongMaterial blue(
        0.2, 0.6, 0.2, 50,
        Color(0, 0, 255),
        Color(0, 0, 255),
        Color(255, 255, 255)
    );
    CheckMaterial checker_material(
        0.005, 0.2, 0.6, 0.2, 10,
        Color(255, 255, 255),
        Color(255, 255, 255)
    );

    Sphere sphere_1(Vector3(-200, 0, -1150), 200, &red);
    Sphere sphere_2(Vector3(100, 200, -1800), 400, &white);
    Sphere sphere_3(Vector3(200, -100, -900), 100, &blue);
    Plane plane_1(Vector3(0, 1, 0), 200.0, &checker_material);

    Geometry *geos[4] = {&sphere_1, &sphere_2, &sphere_3, &plane_1};

    GeometryUnion geometry_union(4, geos);
    
    FILE *f = fopen("test.png", "wb");
    if(!f) {
        std::cout << "Create file failed, please try again." << std::endl;
    }
    else {
        RenderEngine render_engine(WIDTH, HEIGHT, SAMPLE_TIMES, MAX_REFLECT_TIMES);
        render_engine.render(camera, geometry_union, f, output_img_data);
        // render_engine.test(camera, geometry_union);
        // fclose(f);
    }

    return 0;
}