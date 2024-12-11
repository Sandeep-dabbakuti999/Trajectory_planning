#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template<typename S>
class CartesianCoord{
vector <S> t_index,a_t,b_t,c_t,d_t;
vector <S> hrd,t_coord;
ifstream t_course;
public:
vector<S> load(string file_name);
void print();
//void Resolution(int N);
//void Interpolation(); 

};
#endif