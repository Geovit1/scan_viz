#include "data_rider/Sbgdata.h"

namespace drider {
  
    Sbgdata<SbgLine>::Sbgdata(std::string filepath, char sep): AbstrDataCsv<SbgLine>()
    {
        m_filepath = filepath;
        m_file.open(m_filepath);
        separator = sep;
        std::string header;
        std::getline(m_file,header);
    }

    Sbgdata<SbgLine>::~Sbgdata()
    {
        m_file.close();
    }

    SbgLine Sbgdata<SbgLine>::ParseCsvString(std::string raw)
    {
        SbgLine data;

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
                case CsvHeader::YEAR:
                    data.year = std::stoi(record[i]);
                    break;
                case CsvHeader::MONTH:
                    data.month = std::stoi(record[i]);
                    break;
                case CsvHeader::DAY:
                    data.day = std::stoi(record[i]);
                    break;
                case CsvHeader::HOUR:
                    data.hour = std::stoi(record[i]);
                    break;
                case CsvHeader::MINUTE:
                    data.minute = std::stoi(record[i]);
                    break;
                case CsvHeader::SECOND:
                    data.second = std::stoi(record[i]);
                    break;
                case CsvHeader::UTC_NANOSECOND:
                    data.utc_nanosecond = std::stoul(record[i]);
                    break;
                case CsvHeader::GPS_WEEK:
                    data.gps_week = std::stoul(record[i]);
                    break;
                case CsvHeader::CLOCK_STABLE:
                    data.clock_stable = (bool)std::stoi(record[i]);
                    break;
                case CsvHeader::CLOCK_STATUS:
                    data.clock_status = (bool)std::stoi(record[i]);
                    break;
                case CsvHeader::CLOCK_UTC_SYNC:
                    data.clock_utc_sync = (bool)std::stoi(record[i]);
                    break;
                case CsvHeader::CLOCK_UTC_STATUS:
                    data.clock_utc_status = (bool)std::stoi(record[i]);
                    break;
                case CsvHeader::ROLL:
                    data.roll = std::stod(record[i]);
                    break;
                case CsvHeader::PITCH:
                    data.pitch = std::stod(record[i]);
                    break;
                case CsvHeader::YAW:
                    data.yaw = std::stod(record[i]);
                    break;
                case CsvHeader::NORTH:
                    data.pitch = std::stod(record[i]);
                    break;
                case CsvHeader::EAST:
                    data.east = std::stod(record[i]);
                    break;
                case CsvHeader::DOWN:
                    data.down = std::stod(record[i]);
                    break;
                case CsvHeader::LATITUDE:
                    data.latitude = std::stod(record[i]);
                    break;
                case CsvHeader::LONGITUDE:
                    data.longitude = std::stod(record[i]);
                    break;
                case CsvHeader::ATTITUDE:
                    data.attitude = std::stod(record[i]);
                    break;
                case CsvHeader::UNDULATION:
                    data.undulation = std::stoi(record[i]);
                    break;
                case CsvHeader::SOLUTION_MODE:
                    data.solution_mode = std::stoi(record[i]);
                    break;
            }
            
        }

        return data;
    }
}