#include "mathmodel/CoordinateSystems.h"

namespace mathmodel
{

    void InitSpher(double a, double f, double &b, double &c, double &e2, double &e12)
    {
        b = a * (1. - f);
        c = a / (1. - f);
        e2 = f * (2. - f);
        e12 = e2 / (1. - e2);
    }


    ublas::vector<double> GeographicToGeocentric(double lat, double lon,
                                                 double h, double a, double f)
    {
        ublas::vector<double> v(3);

        double b, c, e2, e12;
        InitSpher(a, f, b, c, e2, e12);
        double cos_lat = cos(lat);
        double n = c / sqrt(1. + e12 * cos_lat * cos_lat);
        double p = (n + h) * cos_lat;
        v[0] = p * cos(lon);
        v[1] = p * sin(lon);
        v[2] = (n + h - e2 * n) * sin(lat);

        return v;
    }

}
