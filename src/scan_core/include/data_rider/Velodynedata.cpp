#include "data_rider/Velodynedata.h"

namespace drider {
  
    Velodynedata<VelodyneLine>::Velodynedata(std::string filepath, char sep): AbstrDataCsv<VelodyneLine>()
    {
        m_filepath = filepath;
        m_file.open(m_filepath);
        separator = sep;
        std::string header;
        std::getline(m_file,header);
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
            if (!getline( ss, s, separator)) break;
                record.push_back( s );
        }

        for(int i=0; i<record.size(); i++){
            switch (i)
            {
                case CsvHeader::ROS_TIMESTAMP:
                    data.ros_timestamp = std::stoul(record[i]);
                    break;
                case CsvHeader::PACKET_STAMP:
                    data.packet_stamp = std::stoul(record[i]);
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
}