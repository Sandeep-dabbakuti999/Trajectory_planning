#ifndef FRENET_H
#define FRENET_H
#include <iostream>
#include <vector>
using namespace std;
class Frenet{
    public:
    int Perpen_Point(double C_X,double C_Y,vector<double> X_coord,vector<double> Y_coord);
    double Long_displacement(double inc,int N);
    double Lateral_displacement(double c_x,double c_y,double x,double y);
};
#endif 