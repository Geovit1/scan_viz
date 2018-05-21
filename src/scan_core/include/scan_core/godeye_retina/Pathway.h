#pragma once

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <vector>
#include <iostream>

#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/transforms.h>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "scan_core/godeye_retina/Generator.h"

namespace godeye_retina
{
    class Pathway
    {
    public:
        Pathway(std::string frameid);
        virtual ~Pathway(){};

        void ClearPathway();
        void SetFrameId(std::string frameid);
    protected:
        nav_msgs::Path m_pathway;

    };
    
}