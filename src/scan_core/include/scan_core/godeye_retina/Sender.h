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
    class Sender
    {
    public:
        Sender(ros::NodeHandle &n);
        virtual ~Sender(){};

        void GetNextBundle(pcl::PointCloud<pcl::PointXYZI> &cloud,
                            ublas::vector<double> &pos_xyz, ublas::vector<double> &rpy);

        void PublishBundle(pcl::PointCloud<pcl::PointXYZI> &cloud,
                            ublas::vector<double> &pos_xyz, ublas::vector<double> &rpy);

        AbstrGenerator *generator = nullptr;

        ros::Publisher odom_pub;
        ros::Publisher pathway_pub;
        ros::Publisher pointcloud_pub;

        void ClearPathway();
    protected:
        ros::Time m_current_time, m_last_time;
        tf::TransformBroadcaster m_odom_broadcaster;

        std::string m_frameid_pathway = "odom";
        std::string m_frameid_pointcloud_local = "base_link";
        std::string m_frameid_pointcloud = "odom";
        std::string m_frameid_odom = "odom";
        std::string m_frameid_base = "base_link";

        nav_msgs::Path m_pathway;
    };
    
}
