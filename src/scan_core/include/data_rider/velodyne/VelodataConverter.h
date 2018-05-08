#pragma once

#include <opencv2/opencv.hpp>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/transforms.h>


#include "data_rider/velodyne/DataUnpacker.h"

namespace drider { namespace velodyne {
    
    class VeloPacket
    {
    public:
      velodyne_msgs::VelodyneScan::ConstPtr pc_;

  
      VeloPacket(const velodyne_msgs::VelodyneScan::ConstPtr &pc) :
        pc_(pc)
      {}
    };

    class VelodataConverter
    {
    public:
        VelodataConverter(std::string calibration_file, std::string setting_file);
        ~VelodataConverter(){};
        
        void VeloPacket_To_PCL2(std::vector<VeloPacket> &velodata, int inx, pcl::PointCloud<pcl::PointXYZI>  &out_cloud);

        void VeloPacketBag_To_CSV(std::string bagFile, std::string csvFile);

        void LoadVelopacketBag(std::vector<VeloPacket> &velodata,std::string bagname);
    private:
        DataUnpacker *rawdata;
    };

}}
