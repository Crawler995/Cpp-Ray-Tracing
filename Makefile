main: main.o vector3.o ray3.o sphere.o perspective_camera.o geometry_union.o color.o
	g++ -o main main.o vector3.o ray3.o sphere.o perspective_camera.o geometry_union.o color.o
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

clean:
	rm *.o *.exe