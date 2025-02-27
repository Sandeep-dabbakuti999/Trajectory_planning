#include <iostream>
#include <string>
#include <thread>
#include <cmath>
#include <iterator>
#include <limits>
#include "Data.h"
#include "Frenet.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/types/span.h"
#include "Eigen/SparseCore"
#include "osqp++.h"
using namespace std;

using ::Eigen::SparseMatrix;
using ::Eigen::Triplet;
using ::Eigen::VectorXd;

namespace osqp{
int main(){
   
    CartesianCoord coordinate1,coordinate2;
    Frenet Convertcoord;
    vector<double> X_coord, Y_coord;
    const double A {100},B{100},C{20},D{20},E{20},F{20},G{20};
    double C_x{5},C_y{5};
    thread t1 ([&coordinate1,&X_coord](){
            coordinate1.load("../TestTrack/course_x.txt");
            coordinate1.Resolution(50);
            X_coord=coordinate1.Interpolation();
    });

    thread t2 ([&coordinate2,&Y_coord](){
            coordinate2.load("../TestTrack/course_y.txt");
            coordinate2.Resolution(50);
            Y_coord= coordinate2.Interpolation();
    });
    t1.join();
    t2.join();

    const double kInfinity = std::numeric_limits<double>::infinity();
    double inc=X_coord.at(1)-X_coord.at(0);
    int near_p=Convertcoord.Perpen_Point(C_x,C_y,X_coord,Y_coord);
    double s_l=Convertcoord.Long_displacement(inc,near_p);
    double d_l=Convertcoord.Lateral_displacement(C_x,C_y,X_coord.at(near_p),Y_coord.at(near_p));
    cout<<"The s and d of the car current location"<<" "<<s_l<<" "<<d_l<<endl;
    


    SparseMatrix<double> objective_Matrix(7,7);
    const Triplet<double> kTripletsO[]={{0,0,2*A},{1,1,2*B},{2,2,2*C},{3,3,2*D},{4,4,2*E},{5,5,2*F},{6,6,G}};
    objective_Matrix.setFromTriplets(std::begin(kTripletsO),std::end(kTripletsO));
    SparseMatrix<double> constraint_Matrix(7,2);
    OsqpInstance instance;
    instance.objective_matrix = objective_Matrix;
    instance.objective_vector.resize(7);
    instance.objective_vector << 1,1,0,0,0,0,0;
    instance.constraint_matrix = constraint_Matrix;
    instance.lower_bounds.resize(7);
    instance.lower_bounds <<0,-3.5,-30,-5,-5,0,-1;
    instance.upper_bounds.resize(1);
    instance.upper_bounds <<kInfinity,3.5,30,5,5,30,1;
    
    OsqpSolver solver;
    OsqpSettings settings;
    // Edit settings if appropriate.
    auto status = solver.Init(instance, settings);
    // Assuming status.ok().
    OsqpExitCode exit_code = solver.Solve();
    // Assuming exit_code == OsqpExitCode::kOptimal.
    double optimal_objective = solver.objective_value();
    Eigen::VectorXd optimal_solution = solver.primal_solution();
};

};