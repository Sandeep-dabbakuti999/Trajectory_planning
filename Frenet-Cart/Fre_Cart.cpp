#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Fre_Cart.h>

using namespace std;

vector<vector<double>> Frenet_Cart::V_Model(vector<vector<double>> SD_o,double V_x,double l,double alpha_o,double D_T,double K_R,double dt,double K_r,double Yn){
    double s_n{0},d_n{0},alpha_n{0},ds_n{0},sd_n{0},dd_n{0},dds_n{0};
    vector<vector<double>> opt;
    s_n=SD_o[1][1]+((V_x*cos(alpha_o))/(1-K_r*SD_o[1][2]))*dt;
    d_n=SD_o[1][2]+V_x*sin(alpha_o)*dt;
    alpha_n=alpha_o+(((V_x/l)*tan(Yn)-(V_x*cos(D_T)))/(1-K_r*SD_o[1][2]))*dt;
    ds_n=SD_o[1][3]+(1-K_r*SD_o[1][2])*tan(alpha_o)*dt;
    sd_n=SD_o[1][4]+s_n*dt;
    dd_n=SD_o[1][5]+d_n*dt;
    dds_n=SD_o[1][6]+ds_n*dt;
    opt.push_back({s_n,d_n,alpha_n,ds_n});
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