#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class CartesianCoord{
public:
vector <double> t_index,a_t,b_t,c_t,d_t,hrd;
void load(const string file_name);
void Resolution(int N);
vector<double> Interpolation(); 
};
#endif