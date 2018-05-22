#pragma once

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <vector>
#include <iostream>

#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/transforms.h>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "data_rider/csv/Finaldata.h"
#include "data_rider/csv/PointTimeRef.h"
#include "mathmodel/CoordinateSystems.h"

using namespace boost::numeric;
using namespace drider::csv;

namespace godeye_retina
{
    class AbstrGenerator
    {
    public:
        virtual void NextData(pcl::PointCloud<pcl::PointXYZI> &cloud, ublas::vector<double> &pos_xyz, ublas::vector<double> &rpy){}
        virtual void OnStartPosition(){}
        virtual void SetBundleSize(unsigned int bundle_size){}
    protected:
    private:
    };
    

    class GeneratorFinalData:public AbstrGenerator
    {
    public:
        GeneratorFinalData(std::string filepath);
        ~GeneratorFinalData();

        virtual void NextData(pcl::PointCloud<pcl::PointXYZI> &cloud, ublas::vector<double> &pos_xyz, ublas::vector<double> &rpy);
        virtual void OnStartPosition();
        virtual void SetBundleSize(unsigned int bundle_size);

    protected:
    private:
        drider::csv::Finaldata<FinalDataLine> m_csvdata;
        unsigned int m_bundle_size = 50000;

        ublas::vector<double> m_start_offset_xyz = ublas::vector<double>(3);
    };

    class GeneratorTrajectory:public AbstrGenerator
    {
    public:
        GeneratorTrajectory(std::string filepath);
        ~GeneratorTrajectory();

        virtual void NextData(pcl::PointCloud<pcl::PointXYZI> &cloud, ublas::vector<double> &pos_xyz, ublas::vector<double> &rpy);
        virtual void OnStartPosition();
        virtual void SetBundleSize(unsigned int bundle_size);

    protected:
    private:
        drider::csv::PointTimeRef<PointTimeRefLine> m_csvdata;
        unsigned int m_bundle_size = 1;
        int m_count=0;
    };

}