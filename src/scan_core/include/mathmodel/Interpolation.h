#pragma once
#include "mathmodel/TimeRefTypes.h"
#include "mathmodel/Rotations.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

namespace mathmodel
{
    template <typename T1, typename T2>  
    T1 interpolate(T1 target , T2 left_bound, T2 right_bound);

    template <>
    Point interpolate(Point target, Rotation left_bound, Rotation right_bound);
}