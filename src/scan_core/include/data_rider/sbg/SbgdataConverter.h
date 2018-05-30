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

#include <sbg_driver/SbgEkfEuler.h>
#include <sbg_driver/SbgEkfNav.h>
#include <sbg_driver/SbgEkfStatus.h>
#include <sbg_driver/SbgEvent.h>
#include <sbg_driver/SbgGpsHdt.h>
#include <sbg_driver/SbgGpsPos.h>
#include <sbg_driver/SbgGpsPosStatus.h>
#include <sbg_driver/SbgGpsRaw.h>
#include <sbg_driver/SbgGpsVel.h>
#include <sbg_driver/SbgGpsVelStatus.h>
#include <sbg_driver/SbgImuData.h>
#include <sbg_driver/SbgImuStatus.h>
#include <sbg_driver/SbgMag.h>
#include <sbg_driver/SbgMagCalib.h>
#include <sbg_driver/SbgMagStatus.h>
#include <sbg_driver/SbgOdoVel.h>
#include <sbg_driver/SbgPressure.h>
#include <sbg_driver/SbgShipMotion.h>
#include <sbg_driver/SbgShipMotionStatus.h>
#include <sbg_driver/SbgStatus.h>
#include <sbg_driver/SbgStatusAiding.h>
#include <sbg_driver/SbgStatusCom.h>
#include <sbg_driver/SbgStatusGeneral.h>
#include <sbg_driver/SbgUtcTime.h>
#include <sbg_driver/SbgUtcTimeStatus.h>
#include <velodyne_gps/HDL32eOver.h>


#include "data_rider/InterfaceDevice.h"

namespace drider { namespace sbg {
    
    class SBG
    {
    public:
      sbg_driver::SbgEkfEuler::ConstPtr ekfEuler_;
      sbg_driver::SbgEkfNav::ConstPtr ekfNav_;
      sbg_driver::SbgUtcTime::ConstPtr utc_;

  
      SBG(const sbg_driver::SbgEkfEuler::ConstPtr &ekfEuler, 
                  const sbg_driver::SbgEkfNav::ConstPtr &ekfNav, 
                  const sbg_driver::SbgUtcTime::ConstPtr &utc) :
        ekfEuler_(ekfEuler),
        ekfNav_(ekfNav),
        utc_(utc)
      {}
    };

    void callback(const sbg_driver::SbgEkfEuler::ConstPtr &ekfEuler, 
              const sbg_driver::SbgEkfNav::ConstPtr &ekfNav, 
              const sbg_driver::SbgUtcTime::ConstPtr &utc)
    {
        SBG sbg(ekfEuler, ekfNav, utc);

        // Stereo dataset is class variable to store data
        SBG_data_.push_back(sbg);
    }

    class SbgdataConverter: InterfaceDeviceImu, InterfaceDeviceGPS
    {
    public:
        SbgdataConverter(std::string calibration_file, std::string setting_file);
        ~SbgdataConverter(){};
        
        virtual void Convert_BagToCsv(std::string in_bagfile){};
        virtual void Convert_BagToBin(std::string in_bagfile){};
        virtual void Convert_CsvToBin(std::string in_bagfile){};
        virtual void Convert_BinToCsv(std::string in_bagfile){};
    private:
        DataUnpacker *rawdata;
    };

}}

