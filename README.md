# Cpp Ray Tracing
A ray tracing study and test written by C++.<br>
Still studying, the code will be often updated.

## Compile
The program is compiled by `MinGW`. Please use `MinGW` to compile it if you want to save the time. IF YOU CAN, you can use other compiler.<br>
For most college students, they must have installed `Dev-C++` to study `C/C++`. If you did it, your computer have installed the `MinGW` in the `Dev-C++` installation path. If not, you can download it in its official website.<br>
Find the exe named `mingw32-make.exe` in the `MinGW` installation path. In my computer the path is `MinGW64/bin/mingw32-make.exe`. Please ensure the path is added to the `environment PATH`.<br>
After that, go to the program folder, open the command line and input like this:
```
$ mingw32-make
$ main
```
Wait a moment, after rendering you can find `test.png` in the folder.
  
## Feature
No complicated and new C++ feature, based on very easy C++.<br>
Be suitable for the people who know about C++, begin to study Ray Tracing.<br>
There is no comment in the code, I will add it in the future.

## Render result
![1920*1080, 20 sample times, all Phong Material](https://github.com/Crawler995/Cpp-Ray-Tracing/blob/master/test_1.png)
1920*1080, sample times: 20, all Phong Material

![1920*1080, 20 sample times, left Cook-Torrance Material, right Phong Material](https://github.com/Crawler995/Cpp-Ray-Tracing/blob/master/test_2.png)
1920*1080, 20 sample times, left Cook-Torrance Material, right Phong Material

## Reference
1. [JavaScript玩转计算机图形学（一）光线追踪入门](http://www.cnblogs.com/miloyip/archive/2010/03/29/1698953.html)
2. [Phong光照模型](https://wenku.baidu.com/view/4e6443ea9b89680202d8250f.html)
3. [Ray Tracing in a weekend](http://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf)
4. [Cook-Torrance光照模型](https://www.cnblogs.com/jqm304775992/p/5202973.html)
5. 《计算机图形学与虚拟环境》 机械工业出版社
