#include <iostream>
#include <string>
#include <thread>
#include "Data.h"
using namespace std;


int main(){
   
    CartesianCoord coordinate1,coordinate2;
    thread t1 ([&coordinate1](){
            coordinate1.load("../TestTrack/course_x.txt");
            coordinate1.Resolution(coordinate1.t_index,10);
            coordinate1.Interpolation();
    });

    thread t2 ([&coordinate2](){
            coordinate2.load("../TestTrack/course_y.txt");
            coordinate2.Resolution(coordinate2.t_index,10);
            coordinate2.Interpolation();
    });
    t1.join();
    t2.join();
};