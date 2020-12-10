#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>
#define _USE_MATH_DEFINES
int main(){
    /* 
    * PA 0
    */
    // TO DO: Define point P
    // TO DO: Define rotation matrix M
    // TO DO: M * P
    Eigen::Vector3f v(2.0f, 1.0f, 1.0f);
    Eigen::Matrix3f rota;
    Eigen::Matrix3f tran;
    double theta = 45.0 / 180.0 * M_PI;
    rota << cos(theta), -sin(theta), 0,
            sin(theta), cos(theta), 0,
            0, 0, 1;
    tran << 1, 0, 1,
            0, 1, 2,
            0, 0, 1;
    v = tran * rota * v;
    std::cout << v << std::endl;
    std::cout<< v[0] << " " << v[1] << std::endl;
    return 0;
}