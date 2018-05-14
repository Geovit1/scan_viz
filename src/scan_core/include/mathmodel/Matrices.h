#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/io.hpp>




using namespace boost::numeric;

namespace mathmodel {

 
    template <class T>
    class Matrix : public ublas::matrix<T> 
    {
        public:
            Matrix() : parent(ublas::matrix<T>()){}
            Matrix(ublas::matrix<T> mat) : parent(mat){}
            Matrix(int x, int y){ublas::matrix<T>(x,y);} 
            Matrix<T> operator* (Matrix<T> mat);
        private:
            ublas::matrix<T> parent;    
    };
    
    template <>
    class Matrix<double> : public ublas::matrix<double> 
    {
        public:
            Matrix() : parent(ublas::matrix<double>()){}
            Matrix(ublas::matrix<double> mat) : parent(mat){}
            Matrix(int x, int y){ublas::matrix<double>(x, y);}

            Matrix<double> operator* (Matrix<double> mat);
        private:
            ublas::matrix<double> parent;
    };

}