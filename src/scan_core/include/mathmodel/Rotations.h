#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/io.hpp>




using namespace boost::numeric;


namespace mathmodel 
{
    ublas::matrix<double> GenRotMatX(double roll);
    ublas::matrix<double> GenRotMatY(double pitch);
    ublas::matrix<double> GenRotMatZ(double yaw);
    ublas::matrix<double> GenRotMat(double roll, double pitch, double yaw, std::string order);
    ublas::matrix<double> GenQuatRotMat(double w, double x, double y, double z);
    ublas::matrix<double> GenCustomRotMat(double angle, ublas::vector<double> axis);
    
}