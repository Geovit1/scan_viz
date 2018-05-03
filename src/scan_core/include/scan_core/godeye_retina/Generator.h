#pragma once

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <vector>
#include <iostream>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "data_rider/Finaldata.h"

using namespace boost::numeric;

namespace godeye_retina
{
    class Generator
    {
    public:
        virtual void NextData();
    protected:
    private:
    };
    

    class GeneratorFinalData:Generator
    {
    public:
        GeneratorFinalData();
        ~GeneratorFinalData();
        virtual void NextData();
    protected:
    private:
        drider::fd::Finaldata csvdata;
        unsigned int bundle_size = 10000;
    };

}