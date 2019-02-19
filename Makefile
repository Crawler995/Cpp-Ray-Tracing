main: main.o vector3.o ray3.o sphere.o perspective_camera.o
	g++ -o main main.o vector3.o ray3.o sphere.o perspective_camera.o
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

clean:
	rm *.o *.exe