
#include <fstream>
#include <math.h>

#include <ros/ros.h>
#include <ros/package.h>
#include <angles/angles.h>

#include "data_rider/velodyne/DataUnpacker.h"

namespace drider { namespace velodyne {
  ////////////////////////////////////////////////////////////////////////
  //
  // RawData base class implementation
  //
  ////////////////////////////////////////////////////////////////////////

  DataUnpacker::DataUnpacker() {}
  
  /** Update parameters: conversions and update */
  void DataUnpacker::setParameters(double min_range,
                              double max_range,
                              double view_direction,
                              double view_width)
  {
    config_.min_range = min_range;
    config_.max_range = max_range;
/*
//это надо пересчитать по человечески
    //converting angle parameters into the velodyne reference (rad)
    config_.tmp_min_angle = view_direction + view_width/2;
    config_.tmp_max_angle = view_direction - view_width/2;
    
    //computing positive modulo to keep theses angles into [0;2*M_PI]
    config_.tmp_min_angle = fmod(fmod(config_.tmp_min_angle,2*M_PI) + 2*M_PI,2*M_PI);
    config_.tmp_max_angle = fmod(fmod(config_.tmp_max_angle,2*M_PI) + 2*M_PI,2*M_PI);
    
    //converting into the hardware velodyne ref (negative yaml and degrees)
    //adding 0.5 perfomrs a centered double to int conversion 
    config_.min_angle = 100 * (2*M_PI - config_.tmp_min_angle) * 180 / M_PI + 0.5;
    config_.max_angle = 100 * (2*M_PI - config_.tmp_max_angle) * 180 / M_PI + 0.5;*/
    config_.min_angle = 0;
    config_.max_angle = 36000;
    if (config_.min_angle == config_.max_angle)
    {
      //avoid returning empty cloud if min_angle = max_angle
      config_.min_angle = 0;
      config_.max_angle = 36000;
    }
  }

  void DataUnpacker::readViewField(const std::string& file) 
  {
    double min_range;
    double max_range;
    double view_direction;
    double view_width;

    cv::FileStorage fl(file, cv::FileStorage::READ);
		if(!fl.isOpened()){
			std::cout<<"Error! ....yaml not found... adieu!"<<std::endl;
			exit(1);
		}
			fl ["min_range"] >> min_range;
			fl ["max_range"] >> max_range;
			fl ["view_direction"] >> view_direction;
			fl ["view_width"] >> view_width;
			fl.release();
    setParameters(min_range,max_range,view_direction,view_width);
  }

  int DataUnpacker::setupFromFile(std::string calibration_file, std::string viewfield_file )
  {

      //config_.max_range = 120;
      //config_.min_range = 0.01;
      //ROS_INFO_STREAM("data ranges to publish: ["
	    //  << config_.min_range << ", "
	    //  << config_.max_range << "]");

      config_.calibrationFile = calibration_file;

      ROS_INFO_STREAM("correction angles: " << config_.calibrationFile);

      calibration_.read(config_.calibrationFile);
      if (!calibration_.initialized) {
	        ROS_ERROR_STREAM("Unable to open calibration file: " <<
		      config_.calibrationFile);
	        return -1;
      }

      // Set up cached values for sin and cos of all the possible headings
      for (uint16_t rot_index = 0; rot_index < ROTATION_MAX_UNITS; ++rot_index) {
        float rotation = angles::from_degrees(ROTATION_RESOLUTION * rot_index);
        cos_rot_table_[rot_index] = cosf(rotation);
        sin_rot_table_[rot_index] = sinf(rotation);
      }
      
      readViewField(viewfield_file);

      ROS_INFO_STREAM("data ranges to publish: ["
	      << config_.min_range << ", "
	      << config_.max_range << "]");
      ROS_INFO_STREAM("angle ranges to publish: ["
	      << config_.min_angle << ", "
	      << config_.max_angle << "]");
      return 0;
  }


  double DataUnpacker::Time_offset(int &sequence_inx, int &datapoint_inx)
  {
    return (46.080 * sequence_inx) + (1.152 * datapoint_inx) ; // [µs]
  }

  void DataUnpacker::unpack32(const velodyne_msgs::VelodynePacket &pkt,
                      final_packet &pc)
  {
    pc.stamp_sec = pkt.stamp.sec;
    pc.stamp_nsec = pkt.stamp.nsec;
    const raw_packet *raw = (const raw_packet *) &pkt.data[0];

    pc.gps_time = raw->gpstime; 
  

    //std::cout<<config_.min_range<<" "<< config_.max_range<<" " <<config_.min_angle<<" "<<
       //                config_.max_angle<< std::endl;
    // Цикл по блокам, которых 12 штук
    for (int i = 0; i < BLOCKS_PER_PACKET; i++) //sequence_inx
    {

      // HDL32e - это UPPER_BANK, поэтому начинаем отсчитывать лазеры от 0
      int bank_origin = 0;
      if (raw->blocks[i].header == LOWER_BANK) 
      {
        // lower bank lasers are [32..63]
        bank_origin = 32;
      }

      // Цикл по сканам внутри блока, которых 32
      // Внутри каждого скана есть 3 байта (2 байта расстояния и 1 байт интерсивности)
      for (int j = 0, k = 0; j < SCANS_PER_BLOCK; j++, k += RAW_SCAN_SIZE)  //datapoint_inx 
      {
        
        float x, y, z;
        float intensity;
        double lerp_time;
        uint8_t laser_number;       ///< hardware laser number

        // Задание номера лазера
        laser_number = j + bank_origin;
        LaserCorrection &corrections = calibration_.laser_corrections[laser_number];

        // Вычисление позиции
        // Два байта дистанции
        union two_bytes tmp;
        tmp.bytes[0] = raw->blocks[i].data[k];
        tmp.bytes[1] = raw->blocks[i].data[k+1];

        // Берем те точки, которые внутри требуемого диапазона углов
        //std::cout << raw->blocks[i].rotation << " " << config_.min_angle << " " << config_.max_angle << std::endl;  
        if (
            (raw->blocks[i].rotation >= config_.min_angle 
             && raw->blocks[i].rotation <= config_.max_angle 
             && config_.min_angle < config_.max_angle)
             ||
             (config_.min_angle > config_.max_angle 
             && (raw->blocks[i].rotation <= config_.max_angle 
             || raw->blocks[i].rotation >= config_.min_angle))
             )
        {
// Расчет дистанции
          // DISTANCE_RESOLUTION = 2 mm
          float distance = tmp.uint * DISTANCE_RESOLUTION;
          distance += corrections.dist_correction;
  
          float cos_vert_angle = corrections.cos_vert_correction;
          float sin_vert_angle = corrections.sin_vert_correction;
          float cos_rot_correction = corrections.cos_rot_correction;
          float sin_rot_correction = corrections.sin_rot_correction;
  
          // cos(a-b) = cos(a)*cos(b) + sin(a)*sin(b)
          // sin(a-b) = sin(a)*cos(b) - cos(a)*sin(b)
          float cos_rot_angle = 
            cos_rot_table_[raw->blocks[i].rotation] * cos_rot_correction + 
            sin_rot_table_[raw->blocks[i].rotation] * sin_rot_correction;
          float sin_rot_angle = 
            sin_rot_table_[raw->blocks[i].rotation] * cos_rot_correction - 
            cos_rot_table_[raw->blocks[i].rotation] * sin_rot_correction;
  
          float horiz_offset = corrections.horiz_offset_correction;
          float vert_offset = corrections.vert_offset_correction;
  
          // Compute the distance in the xy plane (w/o accounting for rotation)
          /**the new term of 'vert_offset * sin_vert_angle'
           * was added to the expression due to the mathemathical
           * model we used.
           */
          float xy_distance = distance * cos_vert_angle - vert_offset * sin_vert_angle;
  
          // Calculate temporal X, use absolute value.
          float xx = xy_distance * sin_rot_angle - horiz_offset * cos_rot_angle;
          // Calculate temporal Y, use absolute value
          float yy = xy_distance * cos_rot_angle + horiz_offset * sin_rot_angle;
          if (xx < 0) xx=-xx;
          if (yy < 0) yy=-yy;
    
          float distance_corr_x = 0;
          float distance_corr_y = 0;
          if (corrections.two_pt_correction_available) {
            distance_corr_x = 
              (corrections.dist_correction - corrections.dist_correction_x)
                * (xx - 2.4) / (25.04 - 2.4) 
              + corrections.dist_correction_x;
            distance_corr_x -= corrections.dist_correction;
            distance_corr_y = 
              (corrections.dist_correction - corrections.dist_correction_y)
                * (yy - 1.93) / (25.04 - 1.93)
              + corrections.dist_correction_y;
            distance_corr_y -= corrections.dist_correction;
          }
  
          float distance_x = distance + distance_corr_x;
          /**the new term of 'vert_offset * sin_vert_angle'
           * was added to the expression due to the mathemathical
           * model we used.
           */
          xy_distance = distance_x * cos_vert_angle - vert_offset * sin_vert_angle ;
          ///the expression wiht '-' is proved to be better than the one with '+'
          x = xy_distance * sin_rot_angle - horiz_offset * cos_rot_angle;
  
          float distance_y = distance + distance_corr_y;
          xy_distance = distance_y * cos_vert_angle - vert_offset * sin_vert_angle ;
          /**the new term of 'vert_offset * sin_vert_angle'
           * was added to the expression due to the mathemathical
           * model we used.
           */
          y = xy_distance * cos_rot_angle + horiz_offset * sin_rot_angle;
  
          z = distance_y * sin_vert_angle + vert_offset*cos_vert_angle;
  
          /** Use standard ROS coordinate system (right-hand rule) */
          float x_coord = y;
          float y_coord = -x;
          float z_coord = z;
  
          /** Intensity Calculation */
  
          float min_intensity = corrections.min_intensity;
          float max_intensity = corrections.max_intensity;
  
          intensity = raw->blocks[i].data[k+2];
  
          float focal_offset = 256 
                             * (1 - corrections.focal_distance / 13100) 
                             * (1 - corrections.focal_distance / 13100);
          float focal_slope = corrections.focal_slope;
          intensity += focal_slope * (std::abs(focal_offset - 256 * 
            (1 - static_cast<float>(tmp.uint)/65535)*(1 - static_cast<float>(tmp.uint)/65535)));
          intensity = (intensity < min_intensity) ? min_intensity : intensity;
          intensity = (intensity > max_intensity) ? max_intensity : intensity;

          lerp_time = (double)raw->gpstime + Time_offset( i, j) ;

          //std::cout<<raw->gpstime<<" "<<((double)raw->gpstime);
          //printf("- %f \n ",lerp_time );
          // Берем только те точки, которые находятся в заданном диапазоне
          if (pointInRange(distance)) 
          {
            pc.laser_id.push_back(laser_number);
            pc.lerp_laser_time.push_back(lerp_time);
            pc.distance.push_back(distance);
            pc.x.push_back(x_coord);
            pc.y.push_back(y_coord);
            pc.z.push_back(z_coord);
            pc.intensity.push_back(intensity);   
          }
        }
      }
    }
  }


}}
