# ifndef FRE_CART_H
# define FRE_CART_H
using namespace std;
#include <vector>

class Frenet_Cart{
public:
    vector<vector<double>> V_Model(vector<vector<double>> SD_o,double V_x,double l,double alpha_o,double D_T,double K_R,double dt,double K_r,double Yn); 
    vector<vector<double>> F_Cframe(vector<vector<double>> frenet,double X_r,double Y_r,double T_r,double K_r,double K_dr);
};
#endif