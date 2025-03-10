#include <iostream>
#include <string>
#include <thread>
#include <cmath>
#include <chrono>
#include <iterator>
#include <limits>
#include "Data.h"
#include "Frenet.h"
#include "Optimize.h"
using namespace std;


int main(){
   
    CartesianCoord coordinate1,coordinate2;
    Frenet Convertcoord;
    vector<double> X_coord, Y_coord;
    double C_x{5},C_y{5},time_step{0.5},time{4};
    bool destination{false};
    thread t1 ([&coordinate1,&X_coord](){
            coordinate1.load("../TestTrack/course_x.txt");
            coordinate1.Resolution(50);
            X_coord=coordinate1.Interpolation();
    });

    thread t2 ([&coordinate2,&Y_coord](){
            coordinate2.load("../TestTrack/course_y.txt");
            coordinate2.Resolution(50);
            Y_coord= coordinate2.Interpolation();
    });
    t1.join();
    t2.join();

   //frenet frame coordinates coversion
    double inc=X_coord.at(1)-X_coord.at(0);
    int near_p=Convertcoord.Perpen_Point(C_x,C_y,X_coord,Y_coord);
    double s_l=Convertcoord.Long_displacement(inc,near_p);
    double d_l=Convertcoord.Lateral_displacement(C_x,C_y,X_coord.at(near_p),Y_coord.at(near_p));
    cout<<"The s and d of the car current location"<<" "<<s_l<<" "<<d_l<<endl;

    while(destination){
        for(double step=0;step<=time;step+time_step){
                
        };
    };

   
};
