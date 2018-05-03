#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric;


namespace mathmodel
{
    double semimajor_axis = 6378137.0;
    double flattening = 1.0/298.257223563;

    ublas::vector<double> GeographicToGeocentric(double lan, double lon, double at);
}
