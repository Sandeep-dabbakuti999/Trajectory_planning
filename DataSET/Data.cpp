#include <iostream>
#include <vector>
#include <mutex>
#include <cmath>
#include <algorithm>
#include <fstream>
#include "Data.h"
using namespace std;

mutex mtx;

//Loading a file using a file path
 void CartesianCoord::load(const string file_name){
    lock_guard<mutex> lock(mtx);
    ifstream t_course(file_name);
    double i_x,ax,bx,cx,dx;
    while(t_course>>i_x>>ax>>bx>>cx>>dx){
        t_index.push_back(i_x);
        a_t.push_back(ax);
        b_t.push_back(bx);
        c_t.push_back(cx);
        d_t.push_back(dx);
    };
  
};


//Increment the resolution as per the resolution value
void CartesianCoord::Resolution(int N){
    lock_guard<mutex> lock(mtx);
    double inc=(t_index.back()-t_index.front())/(N*100);
    double sum=t_index.front();
    while(sum < t_index.back()){
       hrd.push_back(sum);
       sum+=inc; 
    };
};


int find_index(vector <double> indexes, int val){
     for(int i=0;indexes.at(i)>val;i++){
          if(indexes.at(i)==val){
             val=i;
          }else if(val<indexes.at(i) && val>indexes.at(i-1)){
             val=i-1;
          };
     };
    return val;
};


// The cubic spline interpolation between two GNSS coordinates 
vector<double> CartesianCoord::Interpolation(){
    lock_guard<mutex> lock(mtx);
    vector<double> Coord;
    for(int i=0;i<hrd.size();i++){
        int index=find_index(t_index,hrd.at(i));
        double diff=hrd.at(i)-t_index.at(index);
        double C=a_t.at(index)*pow(diff,3)+b_t.at(index)*pow(diff,2)+c_t.at(index)*pow(diff,1)+d_t.at(index);
        Coord.push_back(C); 
    };
    return Coord;
};