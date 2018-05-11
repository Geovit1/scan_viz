#include "data_rider/csv/Sbgdata.h"

namespace drider { namespace csv {
  
    Sbgdata<SbgLine>::Sbgdata(std::string filepath, char separator)
                        : AbstrDataCsv<SbgLine>(filepath, separator)
    {
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
            if (!getline( ss, s, m_separator)) break;
                record.push_back( s );
        }

        for(int i=0; i<record.size(); i++){
            switch (i)
            {
                /*case CsvHeader::ROS_TIMESTAMP_SEC:
                    data.ros_timestamp_sec = std::stoul(record[i].substr(0, record[i].find('/')));
                    break;
                case CsvHeader::ROS_TIMESTAMP_NSEC:
                    data.ros_timestamp_nsec = std::stoul(record[i].sub);
                    break;*/
                case CsvHeader::ROS_TIMESTAMP:
                    data.ros_timestamp = record[i];
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

    std::string Sbgdata<SbgLine>::MakeCsvString(SbgLine data)
    {
        std::string s="";
        //s += std::to_string(data.ros_timestamp_sec) + m_separator;
        //s += std::to_string(data.ros_timestamp_nsec) + m_separator;
        s += data.ros_timestamp + m_separator;
        s += std::to_string(data.year) + m_separator; 
        s += std::to_string(data.month) + m_separator;  
        s += std::to_string(data.day) + m_separator; 
        s += std::to_string(data.hour) + m_separator; 
        s += std::to_string(data.minute) + m_separator; 
        s += std::to_string(data.second) + m_separator; 

        s += std::to_string(data.utc_nanosecond) + m_separator; 
        s += std::to_string(data.gps_week) + m_separator;
        s += std::to_string(data.clock_stable) + m_separator;
        s += std::to_string(data.clock_status) + m_separator;
        s += std::to_string(data.clock_utc_sync) + m_separator;
        s += std::to_string(data.clock_utc_status) + m_separator;
        
        s += std::to_string(data.roll) + m_separator;
        s += std::to_string(data.pitch) + m_separator;
        s += std::to_string(data.yaw) + m_separator;
        
        s += std::to_string(data.north) + m_separator;
        s += std::to_string(data.east) + m_separator;
        s += std::to_string(data.down) + m_separator;
        
        s += std::to_string(data.latitude) + m_separator;
        s += std::to_string(data.longitude) + m_separator;
        s += std::to_string(data.attitude) + m_separator;
        
        s += std::to_string(data.undulation) + m_separator;
        s += std::to_string(data.solution_mode) ;
        return s;
    }

    void Sbgdata<SbgLine>::SetDefaultHeader()
    {
        m_header.clear();
        m_header.push_back("ros_timestamp_sec");
        m_header.push_back("ros_timestamp_nsec"); 
        m_header.push_back("year");
        m_header.push_back("month"); 
        m_header.push_back("day");       
        m_header.push_back("hour");       
        m_header.push_back("second");
        m_header.push_back("utc_nanosecond");       
        m_header.push_back("gps_week");  

        m_header.push_back("clock_stable"); 
        m_header.push_back("clock_status");       
        m_header.push_back("clock_utc_sync");
        m_header.push_back("clock_utc_status");           
        
        m_header.push_back("roll");       
        m_header.push_back("pitch");
        m_header.push_back("yaw");           
        
        m_header.push_back("north");       
        m_header.push_back("east");
        m_header.push_back("down");

        m_header.push_back("latitude");       
        m_header.push_back("longitude");
        m_header.push_back("attitude");

        m_header.push_back("undulation");
        m_header.push_back("solution_mode");
    }

}}