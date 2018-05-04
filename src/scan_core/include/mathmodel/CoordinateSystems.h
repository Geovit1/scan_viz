#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric;


namespace mathmodel
{


    ublas::vector<double> GeographicToGeocentric(double lat, double lon, double h, double a, double f); 
    ublas::vector<double> GeographicToGeocentric(double lan, double lon, double at);
}
