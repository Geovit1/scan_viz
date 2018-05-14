#include "mathmodel/Interpolation.h"

using namespace std;

namespace mathmodel 
{

        Point interpolate(Point target, Rotation left_bound, Rotation right_bound) 
        {
            Point res;
            ublas::vector<float> point(3), point_left(3), point_right(3);
            ublas::matrix<float> rot_left(3, 3), rot_right(3, 3);
            
            point[0] = target.x;
            point[1] = target.y;
            point[2] = target.z;
            
            rot_left =  GenRotMat(left_bound.roll, left_bound.pitch, left_bound.yaw, "zyx");
            rot_right = GenRotMat(right_bound.roll, right_bound.pitch, right_bound.yaw, "zyz");

            point_left =  ublas::prod(rot_left, point);
            point_right = ublas::prod(rot_right, point);

            point = (point_left + point_right)/2;
            res.x = point[0];
            res.y = point[1];
            res.z = point[2];
            res.gps_time = target.gps_time;
            
            return res; 



            

            
        }



}