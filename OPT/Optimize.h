#ifndef OPTIMIZE_H
#define OPTIMIZE_H
#include <iostream>

using ::Eigen::VectorXd;
class optimize{
public:
    const double A {100},B{100},C{20},D{20},E{20},F{20},G{20};
    Eigen::VectorXd Opt();
    void get_coord(int coord);
};
#endif
