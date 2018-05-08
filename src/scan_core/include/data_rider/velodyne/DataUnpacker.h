#pragma once

#include <errno.h>
#include <stdint.h>
#include <string>
#include <boost/format.hpp>
#include <math.h>

#include <ros/ros.h>

//#include <velodyne_msgs/VelodynePacket.h>
//#include <velodyne_msgs/VelodyneScan.h>

#include "data_rider/velodyne/velomsgheaders/VelodyneScan.h"

#include "data_rider/velodyne/Calibrator.h"

namespace drider { namespace velodyne {
  /**
   * Raw Velodyne packet constants and structures.
   */
  static const int SIZE_BLOCK = 100;
  static const int RAW_SCAN_SIZE = 3;
  static const int SCANS_PER_BLOCK = 32;
  static const int BLOCK_DATA_SIZE = (SCANS_PER_BLOCK * RAW_SCAN_SIZE);

  static const float ROTATION_RESOLUTION      =     0.01f;  // [deg]
  static const uint16_t ROTATION_MAX_UNITS    = 36000u;     // [deg/100]
  static const float DISTANCE_RESOLUTION      =     0.002f; // [m]

  /** @todo make this work for both big and little-endian machines */
  static const uint16_t UPPER_BANK = 0xeeff;
  static const uint16_t LOWER_BANK = 0xddff;
  
  
  /** Special Defines for VLP16 support **/
  static const int    VLP16_FIRINGS_PER_BLOCK =   2;
  static const int    VLP16_SCANS_PER_FIRING  =  16;
  static const float  VLP16_BLOCK_TDURATION   = 110.592f;   // [µs]
  static const float  VLP16_DSR_TOFFSET       =   2.304f;   // [µs]
  static const float  VLP16_FIRING_TOFFSET    =  55.296f;   // [µs]
  

  static const int PACKET_SIZE = 1206;
  static const int BLOCKS_PER_PACKET = 12;
  static const int PACKET_STATUS_SIZE = 4;
  static const int SCANS_PER_PACKET = (SCANS_PER_BLOCK * BLOCKS_PER_PACKET);

  typedef struct raw_block
  {
    uint16_t header;        ///< UPPER_BANK or LOWER_BANK
    uint16_t rotation;      ///< 0-35999, divide by 100 to get degrees
    uint8_t  data[BLOCK_DATA_SIZE];
  } raw_block_t;

  union two_bytes
  {
    uint16_t uint;
    uint8_t  bytes[2];
  };

  struct raw_packet
  {
    raw_block_t blocks[BLOCKS_PER_PACKET];
    uint32_t gpstime;
    uint8_t type; 
    uint8_t value; 
  };

  struct final_packet
  {
    std::vector<uint8_t> laser_id;
    std::vector<double> lerp_laser_time;
    std::vector<float> distance;
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> z;
    std::vector<int> intensity;
    uint stamp_sec;
    uint stamp_nsec;
    uint gps_time; 
  };

  class DataUnpacker
  {
  public:

    DataUnpacker();
    ~DataUnpacker() {}

    int setupFromFile(std::string calibration_file, std::string viewfield_file ); 
    void unpack32(const velodyne_msgs::VelodynePacket &pkt, final_packet &pc);
    
  private:
    void setParameters(double min_range, double max_range, double view_direction,
                       double view_width);
    void readViewField(const std::string& file);

    double Time_offset(int &sequence_inx, int &datapoint_inx);

    /** configuration parameters */
    typedef struct {
      std::string calibrationFile;     ///< calibration file name
      double max_range;                ///< maximum range to publish
      double min_range;                ///< minimum range to publish
      int min_angle;                   ///< minimum angle to publish
      int max_angle;                   ///< maximum angle to publish
      
      double tmp_min_angle;
      double tmp_max_angle;
    } Config;
    Config config_;

    Calibration calibration_;
    float sin_rot_table_[ROTATION_MAX_UNITS];
    float cos_rot_table_[ROTATION_MAX_UNITS];
    
    /** in-line test whether a point is in range */
    bool pointInRange(float range)
    {
      return (range >= config_.min_range
              && range <= config_.max_range);
    }

  };

}} 