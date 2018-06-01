#pragma once

#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <ros/package.h>

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>

#include <string>

#include "data_rider/sbg/sbgheaders/SbgEkfEuler.h"
#include "data_rider/sbg/sbgheaders/SbgEkfNav.h"
#include "data_rider/sbg/sbgheaders/SbgEkfStatus.h"
#include "data_rider/sbg/sbgheaders/SbgEvent.h"
#include "data_rider/sbg/sbgheaders/SbgGpsHdt.h"
#include "data_rider/sbg/sbgheaders/SbgGpsPos.h"
#include "data_rider/sbg/sbgheaders/SbgGpsPosStatus.h"
#include "data_rider/sbg/sbgheaders/SbgGpsRaw.h"
#include "data_rider/sbg/sbgheaders/SbgGpsVel.h"
#include "data_rider/sbg/sbgheaders/SbgGpsVelStatus.h"
#include "data_rider/sbg/sbgheaders/SbgImuData.h"
#include "data_rider/sbg/sbgheaders/SbgImuStatus.h"
#include "data_rider/sbg/sbgheaders/SbgMag.h"
#include "data_rider/sbg/sbgheaders/SbgMagCalib.h"
#include "data_rider/sbg/sbgheaders/SbgMagStatus.h"
#include "data_rider/sbg/sbgheaders/SbgOdoVel.h"
#include "data_rider/sbg/sbgheaders/SbgPressure.h"
#include "data_rider/sbg/sbgheaders/SbgShipMotion.h"
#include "data_rider/sbg/sbgheaders/SbgShipMotionStatus.h"
#include "data_rider/sbg/sbgheaders/SbgStatus.h"
#include "data_rider/sbg/sbgheaders/SbgStatusAiding.h"
#include "data_rider/sbg/sbgheaders/SbgStatusCom.h"
#include "data_rider/sbg/sbgheaders/SbgStatusGeneral.h"
#include "data_rider/sbg/sbgheaders/SbgUtcTime.h"
#include "data_rider/sbg/sbgheaders/SbgUtcTimeStatus.h"


#include "data_rider/InterfaceDevice.h"
#include "data_rider/csv/Sbgdata.h"

namespace drider { namespace sbg {
    
    class SBGPacket
    {
    public:
      sbg_driver::SbgEkfEuler::ConstPtr ekfEuler_;
      sbg_driver::SbgEkfNav::ConstPtr ekfNav_;
      sbg_driver::SbgUtcTime::ConstPtr utc_;

  
      SBGPacket(const sbg_driver::SbgEkfEuler::ConstPtr &ekfEuler, 
                  const sbg_driver::SbgEkfNav::ConstPtr &ekfNav, 
                  const sbg_driver::SbgUtcTime::ConstPtr &utc) :
        ekfEuler_(ekfEuler),
        ekfNav_(ekfNav),
        utc_(utc)
      {}
    };

    class SbgdataConverter: virtual InterfaceDeviceImu, InterfaceDeviceGPS
    {
    public:
        SbgdataConverter();
        ~SbgdataConverter(){};
        
        virtual void Convert_BagToCsv(std::string in_bagfile, std::string out_csvfile);
        virtual void Convert_BagToBin(std::string in_bagfile, std::string out_binfile){};
        virtual void Convert_CsvToBin(std::string in_csvfile, std::string out_binfile){};
        virtual void Convert_BinToCsv(std::string in_binfile, std::string out_csvfile){};

        virtual void Convert_BagToTrajectory(std::string in_bagfile){};
        virtual void Convert_CsvToTrajectory(std::string in_csvfile){};
        virtual void Convert_BinToTrajectory(std::string in_binfile){};

        void LoadFulldataBag(std::vector<SBGPacket> &SBGPacket, std::string bagfile);
        
    private:
        std::string SBG_ns_ = "/sync";
        std::string ekfEuler_name = SBG_ns_ + "/ekf_euler";
        std::string ekfNav_name = SBG_ns_ + "/ekf_nav";
        std::string utc_name = SBG_ns_ + "/utc_time";
    };

}}

