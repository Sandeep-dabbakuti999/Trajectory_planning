#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Fre_Cart.h>

using namespace std;

vector<vector<double>> Frenet_Cart::V_Model(vector<vector<double>> SD_old,double V_x,double l,double D_T,double K_R,double dt,double K_r,double Yn){
    double s_new{0},d_new{0},alpha_new{0},ds_new{0},sd_new{0},dd_new{0},dds_new{0};
    vector<vector<double>> opt;
    s_new=SD_old[0][0]+((V_x*cos(SD_old[0][2]))/(1-K_r*SD_old[0][2]))*dt;
    d_new=SD_old[0][1]+V_x*sin(SD_old[0][2])*dt;
    alpha_new=SD_old[0][2]+(((V_x/l)*tan(Yn)-(V_x*cos(D_T)))/(1-K_r*SD_old[1][2]))*dt;
    ds_new=SD_old[0][3]+((1-K_r*SD_old[1][2])*tan(SD_old[0][2])*dt);
    sd_new=SD_old[0][4]+s_new*dt;
    dd_new=SD_old[0][5]+d_new*dt;
    dds_new=SD_old[0][6]+ds_new*dt;
    opt.push_back({s_new,d_new,alpha_new,ds_new,sd_new,dd_new,dds_new});
    return opt;
};

vector<vector<double>> Frenet_Cart::F_Cframe(vector<vector<double>> f,double X_r,double Y_r,double T_r,double K_r,double K_dr){
    vector<vector<double>> cart;
    double X_x,Y_x,a_x,T_x,V_x,K_x,D_T;
    for(int i=0;i<f.size();i++){
        for(int j=0;j<f[i].size();j++){
            X_x=X_r-f[i][3]*sin(T_r);
            Y_x=Y_r-f[i][3]*sin(T_r);
            T_x=atan(f[i][4]/(1-K_r*f[i][3]))+T_r;
            V_x=sqrt(pow((f[i][1]*(1-K_r*f[i][3])),2)+pow((f[i][3]*f[i][6]),2));
            D_T=T_x-T_r;
            a_x=((f[i][2]*(1-K_r*f[i][3]))/cos(D_T))+(pow(f[i][1],2)/cos(D_T))*(f[i][4]*(K_x*(1-K_r*f[i][3])/cos(D_T)))-(K_dr*f[i][3]-K_r*f[i][4]);
            K_x=((f[i][7]+(K_dr+K_r*f[i][6]))*tan(D_T))*(pow(cos(D_T),2)/1-K_r*f[i][3])+K_r;
        };
        cart.push_back({X_x,Y_x,T_x,V_x,a_x,K_x});
    };
    return cart;
};