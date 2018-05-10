#include "data_rider/velodyne/VelodataConverter.h"
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

namespace drider { namespace velodyne {

    VelodataConverter::VelodataConverter(std::string calibration_file, std::string setting_file):
            rawdata(new DataUnpacker())
    {
            rawdata->setupFromFile(calibration_file, setting_file);
    }

    void VelodataConverter::VeloPacketBag_To_CSV(std::string bagFile, std::string csvFile)
    {   
        std::vector<VeloPacket> Velodyne_data_;
        LoadVelopacketBag(Velodyne_data_, bagFile);

        std::ofstream fout;
        fout.open(csvFile, std::ios::out | std::ios::binary);
        fout << "ROS_Timestamp_velodyne,packet_stamp,laser_id,gps_time_toh,lerp_laser_time,point_x,point_y,point_z,distance,intensity" << '\n';
        for(std::vector<VeloPacket>::size_type i = 0; i < Velodyne_data_.size(); i++)
        {
           
            for(int j = 0; j < Velodyne_data_[i].pc_->packets.size(); j++) 
            {

                final_packet fpckt; 
                rawdata->unpack32(Velodyne_data_[i].pc_->packets[j], fpckt);


                for(int k = 0; k < fpckt.laser_id.size(); k++) 
                {
                    std::ostringstream streamObj3;
                    streamObj3 << std::fixed;
                    streamObj3 << std::setprecision(3);
                    streamObj3 << fpckt.lerp_laser_time[k];
                    std::string lerp_laser_time = streamObj3.str();

                    //printf("- %f \n ",fpckt.lerp_laser_time[k] );
                    fout <<
                    Velodyne_data_[i].pc_->header.stamp.sec << "/" << Velodyne_data_[i].pc_->header.stamp.nsec << "," <<
                    fpckt.stamp_sec << "/" << fpckt.stamp_nsec << "," <<
                    static_cast< int >(fpckt.laser_id[k]) << "," <<
                    static_cast<uint>(fpckt.gps_time) << "," << 
                    lerp_laser_time << "," << 
                    fpckt.x[k] << "," <<
                    fpckt.y[k] << "," <<
                    fpckt.z[k] << "," <<
                    fpckt.distance[k] << "," <<
                    static_cast < int >(fpckt.intensity[k]) << "\n";
                }
            }
        }
        fout.close();
    }

    void VelodataConverter::VeloPacket_To_PCL2(std::vector<VeloPacket> &velodata, int ind, pcl::PointCloud<pcl::PointXYZI>  &out_cloud)
    {

        if( ( ind >= 0 ) && ( ind < velodata.size() ) )
        {

            std::vector<int> point_count;
            int pcount = 0;
            std::vector<final_packet> packets;

            for(int j = 0; j < velodata[ind].pc_->packets.size(); j++) 
            {
                final_packet pck;
                rawdata->unpack32(velodata[ind].pc_->packets[j], pck);
                packets.push_back(pck);
                pcount +=pck.laser_id.size();
                point_count.push_back(pck.laser_id.size());
            }

            out_cloud.resize(pcount);

            pcount = 0;
            for(int j = 0; j < velodata[ind].pc_->packets.size(); j++) 
            {
                for(int k = 0; k < point_count[j]; k++) 
                {
                    int outindex = pcount + k; 
                    out_cloud.points[ outindex ].x =  packets[j].x[k];
			        out_cloud.points[ outindex ].y =  packets[j].y[k];
			        out_cloud.points[ outindex ].z =  packets[j].z[k];
                    out_cloud.points[ outindex ].intensity = static_cast < int >(packets[j].intensity[k]);
                }
                pcount += point_count[j];
            }
        }

    }

    void VelodataConverter::LoadVelopacketBag(std::vector<VeloPacket> &velodata,std::string bagname)
    {
        rosbag::Bag bag;
        bag.open(bagname, rosbag::bagmode::Read);

        std::string pc_name = "/velodyne_packets";

        std::vector<std::string> topics;
        topics.push_back(pc_name);
        
        rosbag::View view(bag, rosbag::TopicQuery(topics));
        
        foreach(rosbag::MessageInstance const m, view)
        {
            velodyne_msgs::VelodyneScan::ConstPtr pc_buf = m.instantiate<velodyne_msgs::VelodyneScan>();
            if (pc_buf != NULL) 
            { 
                velodata.push_back(pc_buf);
            }
            
        }
        bag.close();
    }
    
}}