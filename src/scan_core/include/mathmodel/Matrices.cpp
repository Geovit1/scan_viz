#include "mathmodel/Matrices.h"


 
namespace mathmodel 
{

    Matrix<double> Matrix<double>::operator*(Matrix<double> mat) 
    {
        int  n = mat.size1(); // число строк первой матрицы
        int  m = mat.size2(); // число столбцов вторйо матрицы
        int  k = this->size1(); // число строк второй матрицы
        int  l = this->size2(); // число столбцов второй матрицы;
        Matrix<double> res(m, k);
        
        axpy_prod(this->parent, mat.parent, res.parent); 
        return res;
        

        

    } 

}