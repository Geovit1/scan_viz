#include "data_rider/csv/Testdata.h"
#include "data_rider/csv/Sbgdata.h"
#include "data_rider/csv/Velodynedata.h"
#include "mathmodel/Interpolation.h"
#include "mathmodel/Rotations.h"
#include "mathmodel/CoordinateSystems.h"
#include "data_rider/dir_brouser/DirBrouser.h"
#include <iostream>
#include <cmath>

using namespace drider::csv;
using namespace drider;
using namespace std;
using namespace mathmodel;
using namespace boost::numeric::ublas;

int main(int argc, char *arv[]) 
{

    matrix<double> mat(3, 3);

    mat = GenRotMatX(-M_PI/2);
    cout << "Поворот вокруг оси X на угол -pi/2" << endl;
    cout << mat << endl;
    cout << endl;

    mat = GenRotMatY(-M_PI/2);
    cout << "Поворот вокруг оси Y на угол -pi/2" << endl;
    cout << mat << endl;
    cout << endl;

    mat = GenRotMatZ(-M_PI/2);
    cout << "Поворот вокруг оси Z на угол -pi/2" << endl;
    cout << mat << endl;
    cout << endl;
    
    mat = GenRotMat(M_PI/2, M_PI/3, M_PI/4, "zyx");
    cout << "Последовательный поворот вокруг оси X на угол pi/2, оси Y на угол pi/4, оси Z на угол pi/4" << endl;
    cout << mat << endl;
    cout << endl;

    return 0;


}