#include "render_engine.h"
#include "ray3.h"
#include "intersect_result.h"
#include "color.h"
#include "perspective_camera.h"
#include "../utils/utils.h"
#include "../utils/svpng.inc"
#include <ctime>
#include <iostream>

RenderEngine::RenderEngine(int w, int h, int st, int rt) {
    image_width = w;
    image_height = h;
    sample_times = st;
    max_reflect_times = rt;
}

Color RenderEngine::ray_tracing_recursive(
    Ray3 ray, 
    GeometryUnion &geo_union, 
    int reflect_times
) {
    IntersectResult res = geo_union.intersect(ray);

    if(res.geometry) {
        double reflectiveness = res.geometry -> get_material().get_reflectiveness();
        Color color = res.geometry -> get_material().sample(ray, res.normal);
        color = color.multiply(1.0 - reflectiveness);

        if(reflect_times < max_reflect_times) {
            Vector3 dir = res.normal.scale(-2.0 * res.normal.dot(ray.get_dir())).add(ray.get_dir());
            ray = Ray3(res.position, dir);
            Color reflect_color = ray_tracing_recursive(ray, geo_union, reflect_times + 1);

            color = color.add(reflect_color.multiply(reflectiveness));
        }

        return color;
    }
    else {
        return Color(0, 0, 0);
    }
}

void RenderEngine::render(
    PerspectiveCamera &camera, 
    GeometryUnion &geo_union,
    FILE *f, 
    unsigned char *output_img_data
) {
    int index = 0;
    int two_percent_num = image_width * image_height / 50;
    unsigned char *p = output_img_data;
    clock_t start, end;
    start = clock();

    std::string progress_char;
    std::cout << "Start rendering..." << std::endl;

    for(int i = image_height - 1; i >= 0; i--) {
        for(int j = 0; j < image_width; j++) {
            Color color(0, 0, 0);

            for(int k = 0; k < sample_times; k++) {
                double u = 1.0 * (j + rand_num_0_to_1()) / image_width;
                double v = 1.0 * (i + rand_num_0_to_1()) / image_height;

                Ray3 ray = camera.generate_ray(u, v);
                IntersectResult res = geo_union.intersect(ray);

                if(res.geometry) {
                    color = color.add(ray_tracing_recursive(ray, geo_union, 0));
                }
            }

            color = color.multiply(1.0 / sample_times);

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

    svpng(f, image_width, image_height, output_img_data, 0);
    
    std::cout << std::endl << "Render done! Spend " << run_time << "s." << std::endl;

    fclose(f);
}