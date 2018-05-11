#include "mathmodel/Rotations.h"

namespace mathmodel 
{
    ublas::matrix<double> GenRotMatX(double roll) 
    {
        ublas::matrix<double> rot(3, 3);
        rot(0, 0) = 1; 
        rot(0, 1) = 0; 
        rot(0, 2) = 0;
        rot(1, 0) = 0;
        rot(1, 1) = cos(roll);
        rot(1, 2) = -sin(roll);
        rot(2, 0) = 0;
        rot(2, 1) = sin(roll);
        rot(2, 2) = cos(roll);
        return rot;
    }

    ublas::matrix<double> GenRotMatY(double pitch) 
    {
        ublas::matrix<double> rot(3, 3);
        rot(0, 0) = cos(pitch);
        rot(0, 1) = 0;
        rot(0, 2) = sin(pitch);
        rot(1, 0) = 0;
        rot(1, 1) = 1;
        rot(1, 2) = 0;
        rot(2, 0) = -sin(pitch);
        rot(2, 1) = 0;
        rot(2, 2) = cos(pitch);
        return rot;
    }

    ublas::matrix<double> GenRotMatZ(double yaw) 
    {
        ublas::matrix<double> rot(3, 3);
        rot(0, 0) = cos(yaw);
        rot(0, 1) = -sin(yaw);
        rot(0, 2) = 0;
        rot(1, 0) = sin(yaw);
        rot(1, 1) = cos(yaw);
        rot(1, 2) = 0;
        rot(2, 0) = 0;
        rot(2, 1) = 0;
        rot(2, 2) = 1;
        return rot;
    }

    ublas::matrix<double> GenRotMat(double roll, double pitch, double yaw, std::string order="zyx") // order - sequence of rotations 
    {
        //ublas::matrix<double> rot(3, 3), tmp(3, 3);
        /*if (order == "zyx") return GenRotMatZ(yaw)   * GenRotMatY(pitch) * GenRotMatX(roll);
        if (order == "xyz") return GenRotMatX(roll)  * GenRotMatY(pitch) * GenRotMatZ(yaw);
        if (order == "zxy") return GenRotMatZ(yaw)   * GenRotMatX(roll)  * GenRotMatY(pitch);
        if (order == "xzy") return GenRotMatX(roll)  * GenRotMatZ(yaw)   * GenRotMatY(pitch);
        if (order == "yzx") return GenRotMatY(pitch) * GenRotMatZ(yaw)   * GenRotMatX(roll);
        else                return GenRotMatY(pitch) * GenRotMatX(roll)  * GenRotMatZ(yaw);
        */

        /*if (order == "zyx") 
        {
            ublas::axpy_prod(GenRotMatY(pitch), GenRotMatX(roll), tmp);
            ublas::axpy_prod(GenRotMatZ(yaw), tmp , rot);
            return rot;
        }
        if (order == "zyx") 
        {
            ublas::axpy_prod(GenRotMatY(pitch), GenRotMatX(roll), tmp);
            ublas::axpy_prod(GenRotMatZ(yaw), tmp , rot);
            return rot;
        }
        if (order == "zyx") 
        {
            ublas::axpy_prod(GenRotMatY(pitch), GenRotMatX(roll), tmp);
            ublas::axpy_prod(GenRotMatZ(yaw), tmp , rot);
            return rot;
        }
        if (order == "zyx") 
        {
            ublas::axpy_prod(GenRotMatY(pitch), GenRotMatX(roll), tmp);
            ublas::axpy_prod(GenRotMatZ(yaw), tmp , rot);
            return rot;
        }
        if (order == "zyx") 
        {
            ublas::axpy_prod(GenRotMatY(pitch), GenRotMatX(roll), tmp);
            ublas::axpy_prod(GenRotMatZ(yaw), tmp , rot);
            return rot;
        }
        if (order == "zyx") 
        {
            ublas::axpy_prod(GenRotMatY(pitch), GenRotMatX(roll), tmp);
            ublas::axpy_prod(GenRotMatZ(yaw), tmp , rot);
            return rot;
        }*/
    }

    ublas::matrix<double> GenQuatRotMat(double w, double x, double y, double z) 
    {
        ublas::matrix<double> rot(3, 3);
        rot(0, 0) = 1 - 2 * y * y - 2 * z * z;
        rot(0, 1) = 2 * x * y - 2 * z * w;
        rot(0, 2) = 2 * x * z + 2 * y * w;
        rot(1, 0) = 2 * x * y + 2 * z * w;
        rot(1, 1) = 1 - 2 * x * x - 2 * z * z;
        rot(1, 2) = 2 * y * z - 2 * x * w;
        rot(2, 0) = 2 * x * z - 2 * y * w;
        rot(2, 1) = 2 * y * z + 2 * x * w;
        rot(2, 2) = 1 - 2 * x * x - 2 * y * y;
        return rot;
    }
    ublas::matrix<double> GenCustomRotMat(double phi, ublas::vector<double> axis) 
    {   
        double x,y,z;
        x = axis[0];
        y = axis[1];
        z = axis[2];
        ublas::matrix<double> rot(3, 3);
        rot(0, 0) = cos(phi) + ((1 - cos(phi) * x * x));
        rot(0, 1) = ((1 - cos(phi)) * x * y) - (sin(phi) * z);
        rot(0, 2) = ((1 - cos(phi)) * x * z) + (sin(phi) * y);
        rot(1, 0) = ((1 - cos(phi)) * y * x) + (sin(phi) * z);
        rot(1, 1) = cos(phi) + ((1 - cos(phi)) * y * y);
        rot(1, 2) = ((1 - cos(phi)) * y * z) - (sin(phi) * x);
        rot(2, 0) = ((1 - cos(phi)) * z * x) - (sin(phi) * y);
        rot(2, 1) = ((1 - cos(phi)) * z * y) + (sin(phi) * x);
        rot(2, 2) = cos(phi) + ((1 - cos(phi)) * z * z);
        return rot;

    }
}