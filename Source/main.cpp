#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include "Data.h"
using namespace std;


int main(){
    
    thread t1 ([] (){ 
        string X_file="TestTrack/course_x.txt";
        CartesianCoord<double> coordinate1;
        coordinate1.load(X_file);
        coordinate1.print();
        std::cout<<"The loading1 is done"<<std::endl;
    }); 
    thread t2 ([] (){
        string Y_file="TestTrack/course_y.txt";
        CartesianCoord<double> coordinate2;
        coordinate2.load(Y_file);
        coordinate2.print();
        std::cout<<"The loading2 is done"<<std::endl;
    });
    t1.join();
    t2.join();
    //coordinate.Resolution(10);
    //std::cout<<"Resolution is improved"<<std::endl;
    //coordinate.Interpolation();
};