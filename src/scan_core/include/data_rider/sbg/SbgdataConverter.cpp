#include "data_rider/sbg/SbgdataConverter.h"
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

namespace drider { namespace sbg {

    SbgdataConverter::SbgdataConverter(){}

    void SbgdataConverter::Convert_BagToCsv(std::string in_bagfile, std::string out_csvfile)
    {
        std::vector<SBGPacket> sbgdata;
        std::cout<<"Load"<<std::endl;
        LoadFulldataBag(sbgdata, in_bagfile);

        csv::Sbgdata<csv::SbgLine> csvdata;
        csvdata.Create(out_csvfile);
        csv::SbgLine tmp_line;
        std::cout<<"Writing"<<std::endl;
        for(int i=0; i<sbgdata.size(); i++)
        {
            tmp_line.ros_timestamp_sec = sbgdata[i].utc_->header.stamp.sec ;
            tmp_line.ros_timestamp_nsec =  sbgdata[i].utc_->header.stamp.nsec ;
            tmp_line.year = sbgdata[i].utc_->year;
            tmp_line.month = sbgdata[i].utc_->month;
            tmp_line.day = sbgdata[i].utc_->day;
            tmp_line.hour = sbgdata[i].utc_->hour;
            tmp_line.minute = sbgdata[i].utc_->min;
            tmp_line.second = sbgdata[i].utc_->sec;

            tmp_line.utc_nanosecond = sbgdata[i].utc_->nanosec;
            tmp_line.gps_week = sbgdata[i].utc_->gps_tow;
            tmp_line.clock_stable = sbgdata[i].utc_->clock_status.clock_stable;
            tmp_line.clock_status = sbgdata[i].utc_->clock_status.clock_status;
            tmp_line.clock_utc_sync = sbgdata[i].utc_->clock_status.clock_utc_sync;
            tmp_line.clock_utc_status = sbgdata[i].utc_->clock_status.clock_utc_status;
            
            tmp_line.roll = sbgdata[i].ekfEuler_->angle.x;
            tmp_line.pitch = sbgdata[i].ekfEuler_->angle.y;
            tmp_line.yaw = sbgdata[i].ekfEuler_->angle.z;

            tmp_line.north = sbgdata[i].ekfNav_->velocity.x;
            tmp_line.east = sbgdata[i].ekfNav_->velocity.y;
            tmp_line.down = sbgdata[i].ekfNav_->velocity.z;

            tmp_line.latitude = sbgdata[i].ekfNav_->position.x;
            tmp_line.longitude = sbgdata[i].ekfNav_->position.y;
            tmp_line.attitude = sbgdata[i].ekfNav_->position.z;

            tmp_line.undulation = sbgdata[i].ekfNav_->undulation ;
            tmp_line.solution_mode = sbgdata[i].ekfEuler_->status.solution_mode;
            csvdata.WriteCsvRaw(tmp_line);
        }
        csvdata.Close();
    }

    void SbgdataConverter::LoadFulldataBag(std::vector<SBGPacket> &sbgdata, std::string bagfile)
    {
        rosbag::Bag bag;
        bag.open(bagfile, rosbag::bagmode::Read);

        // Image topics to load
        std::vector<std::string> topics;
        topics.push_back(ekfEuler_name);
        topics.push_back(ekfNav_name);
        topics.push_back(utc_name);
        
        rosbag::View view(bag, rosbag::TopicQuery(topics));

        bool f1,f2,f3;
        f1 = f2 = f3 = false;
        sbg_driver::SbgEkfEuler::ConstPtr ekfEuler_tmp;
        sbg_driver::SbgEkfNav::ConstPtr ekfNav_tmp;
        sbg_driver::SbgUtcTime::ConstPtr utc_tmp;

        foreach(rosbag::MessageInstance const m, view)
        {

            if (m.getTopic() == ekfEuler_name || ("/" + m.getTopic() == ekfEuler_name))
            {
                //std::cout << "Gavno" << '\n';
                sbg_driver::SbgEkfEuler::ConstPtr ekfEuler_buf = m.instantiate<sbg_driver::SbgEkfEuler>();
                if (ekfEuler_buf != NULL)
                {
                    //std::cout << l_img->header << std::endl;
                    ekfEuler_tmp = ekfEuler_buf;
                    f1 = true;
                }            
            }
            if (m.getTopic() == ekfNav_name || ("/" + m.getTopic() == ekfNav_name))
            {
                sbg_driver::SbgEkfNav::ConstPtr ekfNav_buf = m.instantiate<sbg_driver::SbgEkfNav>();
                if (ekfNav_buf != NULL)
                { 
                    //std::cout << r_img->header << std::endl;
                    ekfNav_tmp = ekfNav_buf;
                    f2 = true;
                }
            }
            if (m.getTopic() == utc_name || ("/" + m.getTopic() == utc_name))
            {
                sbg_driver::SbgUtcTime::ConstPtr utc_buf = m.instantiate<sbg_driver::SbgUtcTime>();
                if (utc_buf != NULL) 
                {
                    //std::cout << l_info->header << std::endl;
                    utc_tmp = utc_buf;
                    f3 = true;
                }        
            }  
            if(f1 && f2 && f3)
            {
                SBGPacket p(ekfEuler_tmp,ekfNav_tmp,utc_tmp);
                sbgdata.push_back(p);
                f1 = f2 = f3 = false;
            }
        }
        bag.close();
    }


}}

