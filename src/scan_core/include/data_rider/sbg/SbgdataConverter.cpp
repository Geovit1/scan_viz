#include "data_rider/sbg/SbgdataConverter.h"
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

namespace drider { namespace sbg {

    SbgdataConverter::SbgdataConverter(){}

    void SbgdataConverter::Convert_BagToCsv(std::string in_bagfile, std::string out_csvfile)
    {

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

