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
#include "libs/cook_torrance_material.h"
#include "libs/render_engine.h"

#define WIDTH 1920
#define HEIGHT 1080
#define SAMPLE_TIMES 1
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
    PhongMaterial phong_white(
        0.2, 0.6, 0.4, 100,
        Color(255, 255, 255),
        Color(255, 255, 255),
        Color(255, 255, 255)
    );
    CookTorranceMaterial cook_torrance_white(
        0.2, 0.6, 0.4, 0.8, 0.1,
        Color(255, 255, 255),
        Color(255, 255, 255),
        Color(255, 255, 255)
    );
    CheckMaterial checker_material(
        0.005, 0.2, 0.6, 0.2, 10,
        Color(255, 255, 255),
        Color(255, 255, 255)
    );

    Sphere sphere_1(Vector3(-300, 0, -1200), 200, &cook_torrance_white);
    Sphere sphere_2(Vector3(300, 0, -1200), 200, &phong_white);
    Plane plane_1(Vector3(0, 1, 0), 200.0, &checker_material);

    Geometry *geos[3] = {&sphere_1, &sphere_2, &plane_1};

    GeometryUnion geometry_union(3, geos);
    
    FILE *f = fopen("test.png", "wb");
    if(!f) {
        std::cout << "Create file failed, please try again." << std::endl;
    }
    else {
        RenderEngine render_engine(WIDTH, HEIGHT, SAMPLE_TIMES, MAX_REFLECT_TIMES);
        render_engine.render(camera, geometry_union, f, output_img_data);
    }

    return 0;
}