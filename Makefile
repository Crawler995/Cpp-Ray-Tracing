main: main.o vector3.o ray3.o sphere.o perspective_camera.o geometry_union.o color.o utils.o material.o phong_material.o checker_material.o plane.o render_engine.o
	g++ -o main main.o vector3.o ray3.o sphere.o perspective_camera.o geometry_union.o color.o utils.o material.o phong_material.o checker_material.o plane.o render_engine.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
vector3.o: libs/vector3.cpp
	g++ -c -o vector3.o libs/vector3.cpp
ray3.o: libs/ray3.cpp
	g++ -c -o ray3.o libs/ray3.cpp
sphere.o: libs/sphere.cpp
	g++ -c -o sphere.o libs/sphere.cpp
perspective_camera.o: libs/perspective_camera.cpp
	g++ -c -o perspective_camera.o libs/perspective_camera.cpp
geometry_union.o: libs/geometry_union.cpp
	g++ -c -o geometry_union.o libs/geometry_union.cpp
color.o: libs/color.cpp
	g++ -c -o color.o libs/color.cpp
utils.o: utils/utils.cpp
	g++ -c -o utils.o utils/utils.cpp
material.o: libs/material.cpp
	g++ -c -o material.o libs/material.cpp
phong_material.o: libs/phong_material.cpp
	g++ -c -o phong_material.o libs/phong_material.cpp
checker_material.o: libs/checker_material.cpp
	g++ -c -o checker_material.o libs/checker_material.cpp
plane.o: libs/plane.cpp
	g++ -c -o plane.o libs/plane.cpp
render_engine.o: libs/render_engine.cpp
	g++ -c -o render_engine.o libs/render_engine.cpp

clean:
	rm *.o *.exe