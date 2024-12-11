#include <iostream>
#include <vector>
#include <mutex>
#include "Data.h"
using namespace std;
mutex mtx;
template <typename S>
 vector<S> CartesianCoord<S>::load(string file_name){
    lock_guard<mutex> lock (mtx);
    t_course.open(file_name);
    double i_x,ax,bx,cx,dx;
    while(t_course>>i_x>>ax>>bx>>cx>>dx){
        t_index.push_back(i_x);
        a_t.push_back(ax);
        b_t.push_back(bx);
        c_t.push_back(cx);
        d_t.push_back(dx);
    };
};


template <typename D>
void CartesianCoord<D>::print()
{   
    lock_guard<mutex> lock (mtx);
    for (auto val : t_index)
    {
        cout << val << endl;
    };
};
/*
void CartesianCoord::Resolution(int N){
    int inc=(*x_index.begin()-*x_index.end())/N*100;
    double sum=0;
    while(sum != *x_index.end()){
        sum+=*x_index.begin();
        hrd.push_back(sum);
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


void CartesianCoord::Interpolation(){
    for(int i=0;i<hrd.size();i++){
        int index=find_index(x_index,hrd.at(i));
        double diff=hrd.at(i)-x_index.at(index);
        double X=a_x.at(index)*pow(diff,3)+b_x.at(index)*pow(diff,2)+c_x.at(index)*pow(diff,1)+d_x.at(index);
        double Y=a_y.at(index)*pow(diff,3)+b_y.at(index)*pow(diff,2)+c_y.at(index)*pow(diff,1)+d_y.at(index);
        X_coord.push_back(X);
        Y_coord.push_back(Y);
    };
};
*/