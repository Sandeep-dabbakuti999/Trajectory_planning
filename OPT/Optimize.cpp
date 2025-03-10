#include<iostream>
#include <string>
#include <thread>
#include <cmath>
#include <chrono>
#include <iterator>
#include <limits>
#include "Data.h"
#include "Frenet.h"
#include "Optimize.h"
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
Eigen::VectorXd optimize::Opt(){

    //Trajectory planning for four seconds till it reaches destination
    const double kInfinity = std::numeric_limits<double>::infinity();

    //   S -> longitudinal displacement,
    //   D -> lateral displacement,
    //   & -> rate of change in heading,
    //   s''' longitudinal jerk, 
    //   d''' lateral jerk, 
    //   s' -> longitudinal velovity,
    //   d' lateral velocity  
   
    //The quadratic objective matrix is comprised of {s,d,&,s''',d''',s',d'}'*{s,d,&,s''',d''',s',d'}*{2*A,0,0,0,0,0,0;0,2*B,0,0,0,0,0;0,0,2*C,0,0,0,0;0,0,0,2*D,0,0,0,0;0,0,0,0,2*E,0,0;0,0,0,0,0,2*F,0;0,0,0,0,0,0,2*G}
    SparseMatrix<double> objective_Matrix(7,7);
    const Triplet<double> kTripletsO[]={{0,0,2*A},{1,1,2*B},{2,2,2*C},{3,3,2*D},{4,4,2*E},{5,5,2*F},{6,6,2*G}};
    objective_Matrix.setFromTriplets(std::begin(kTripletsO),std::end(kTripletsO));
    SparseMatrix<double> constraint_Matrix(1,7);
    //The constraint matrix is comprised of {000000S,00000D0,0000&00,000s'''000,00d'''0000,0s'00000,d'000000}  
    const Triplet<double> kTripletsC[]={{0,6,1},{1,5,1},{2,4,1},{3,3,1},{4,2,1},{5,1,1},{6,0,1}};
    constraint_Matrix.setFromTriplets(std::begin(kTripletsC),std::end(kTripletsC));
    OsqpInstance instance;
    instance.objective_matrix = objective_Matrix;
    instance.objective_vector.resize(7);
    //Initial vector for the objective 
    instance.objective_vector << 1,1,0,0,0,0,0;
    instance.constraint_matrix = constraint_Matrix;
    instance.lower_bounds.resize(7);
    // Contraints 
    instance.lower_bounds <<0,-3.5,-0.52,-2,-2,0,-1;
    instance.upper_bounds.resize(7);
    instance.upper_bounds <<kInfinity,3.5,0.52,2,2,30,1;
    
    OsqpSolver solver;
    OsqpSettings settings;
    // Edit settings if appropriate.
    auto status = solver.Init(instance, settings);
    // Assuming status.ok().
    OsqpExitCode exit_code = solver.Solve();
    // Assuming exit_code == OsqpExitCode::kOptimal.
    double optimal_objective = solver.objective_value();
    Eigen::VectorXd optimal_solution = solver.primal_solution();
    return optimal_solution;
};
};



void get_coord(int val){
    cout<<"The GNSS coordinates of the vehicle:"<<" "<<val<<endl;
};
