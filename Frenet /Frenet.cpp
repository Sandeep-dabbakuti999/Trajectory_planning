#include <iostream>
#include<cmath>
#include "Frenet.h"
#include "Data.h"
using namespace std;

double Frenet::Long_displacement(double i,int N){
    return i*N;
};
double Frenet::Lateral_displacement(double c_x,double c_y,double X_c,double Y_c){
    return sqrt(pow(c_x-X_c,2)+pow(c_y-Y_c,2));
};

//The cartesian coordinate  perpendicular to the car 
int Frenet::Perpen_Point(double c_x,double c_y,vector<double> X_coord,vector<double> Y_coord){
    int i=0;
    double d1,d2; 
    do{
        d1=abs(c_y-Y_coord.at(i));
        i++;
        d2=abs(c_y-Y_coord.at(i));
    }while(d1>d2);
    return i;
};