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
    if(! t_course.is_open()){
        cout<<"The file cant be opened"<<endl;
    };
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
void CartesianCoord::Resolution(vector<double> ind,int N){
    lock_guard<mutex> lock(mtx);
    double inc=(ind.back()-ind.front())/(N*100);
    double sum=ind.front();
    while(sum < ind.back()){
       hrd.push_back(sum);
       sum+=inc; 
    };
};


int find_index(vector <double> indexes, int val){
    int index;
    for(int i=0;val<=indexes.at(i);i++){
        if(indexes.at(i)==val){
            index=i;
        }else if(val<indexes.at(i) && val>indexes.at(i-1)){
            index=i-1;
        };
    };
    return index;
};

// The cubic spline interpolation between two GNSS coordinates 
void CartesianCoord::Interpolation(){
    for(int i=0;i<hrd.size();i++){
        // int index=find_index(t_index,hrd.at(i));
        // double diff=hrd.at(i)-t_index.at(index);
        // double X=a_t.at(index)*pow(diff,3)+b_t.at(index)*pow(diff,2)+c_t.at(index)*pow(diff,1)+d_t.at(index);
        // double Y=a_t.at(index)*pow(diff,3)+b_t.at(index)*pow(diff,2)+c_t.at(index)*pow(diff,1)+d_t.at(index);
        // X_coord.push_back(X);
        // Y_coord.push_back(Y);
    };
};