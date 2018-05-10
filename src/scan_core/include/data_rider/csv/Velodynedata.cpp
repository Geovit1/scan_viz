#include "data_rider/csv/Velodynedata.h"

namespace drider { namespace csv {
  
    Velodynedata<VelodyneLine>::Velodynedata(std::string filepath, char sep)
        : AbstrDataCsv<VelodyneLine>(filepath, sep)
    {
    }

    Velodynedata<VelodyneLine>::~Velodynedata()
    {
        m_file.close();
    }

    VelodyneLine Velodynedata<VelodyneLine>::ParseCsvString(std::string raw)
    {
        VelodyneLine data;

        std::istringstream ss( raw );
        std::vector <std::string> record;

        while (ss)
        {
            std::string s;
            if (!getline( ss, s, m_separator)) break;
                record.push_back( s );
        }

        for(int i=0; i<record.size(); i++){
            switch (i)
            {
                case CsvHeader::ROS_TIMESTAMP_SEC:
                    data.ros_timestamp_sec = std::stoul(record[i]);
                    break;
                case CsvHeader::ROS_TIMESTAMP_NSEC:
                    data.ros_timestamp_sec = std::stoul(record[i]);
                    break;
                case CsvHeader::PACKET_STAMP_SEC:
                    data.packet_stamp_sec = std::stoul(record[i]);
                    break;
                case CsvHeader::PACKET_STAMP_NSEC:
                    data.packet_stamp_nsec = std::stoul(record[i]);
                    break;
                case CsvHeader::LASER_ID:
                    data.laser_id = std::stoi(record[i]);
                    break;
                case CsvHeader::GPS_TIME_TOH:
                    data.gps_time_toh = std::stoul(record[i]);
                    break;
                case CsvHeader::LERP_LASER_TIME:
                    data.lerp_laser_time = std::stoul(record[i]);
                    break;
                case CsvHeader::POINT_X:
                    data.x = std::stod(record[i]);
                    break;
                case CsvHeader::POINT_Y:
                    data.y = std::stod(record[i]);
                    break;
                case CsvHeader::POINT_Z:
                    data.z = std::stod(record[i]);
                    break;
                case CsvHeader::DISTANCE:
                    data.distance = std::stod(record[i]);
                    break;
                case CsvHeader::INTENSITY:
                    data.intensity = std::stod(record[i]);
                    break;
            }
            
        }

        return data;
    }

    std::string Velodynedata<VelodyneLine>::MakeCsvString(VelodyneLine data)
    {
        std::string s="";
        s += std::to_string(data.ros_timestamp_sec) + m_separator;
        s += std::to_string(data.ros_timestamp_nsec) + m_separator;
        s += std::to_string(data.packet_stamp_sec) + m_separator; 
        s += std::to_string(data.packet_stamp_nsec) + m_separator;  
        s += std::to_string(data.laser_id) + m_separator; 
        s += std::to_string(data.gps_time_toh) + m_separator; 
        s += std::to_string(data.lerp_laser_time) + m_separator; 
        s += std::to_string(data.x) + m_separator; 
        s += std::to_string(data.y) + m_separator; 
        s += std::to_string(data.z) + m_separator;
        s += std::to_string(data.distance) + m_separator;
        s += std::to_string(data.intensity) ;
        return s;
    }

    void Velodynedata<VelodyneLine>::SetDefaultHeader()
    {
        m_header.clear();
        m_header.push_back("ros_timestamp_sec");
        m_header.push_back("ros_timestamp_nsec"); 
        m_header.push_back("packet_stamp_sec");
        m_header.push_back("packet_stamp_nsec"); 
        m_header.push_back("laser_id");       
        m_header.push_back("gps_time_toh");       
        m_header.push_back("lerp_laser_time");
        m_header.push_back("point_x");       
        m_header.push_back("point_y");       
        m_header.push_back("point_z"); 
        m_header.push_back("distance");       
        m_header.push_back("intensity");           
    }


}}