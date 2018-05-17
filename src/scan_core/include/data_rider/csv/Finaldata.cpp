#include "data_rider/csv/Finaldata.h"

namespace drider { namespace csv {
  
    Finaldata<FinalDataLine>::Finaldata(std::string filepath): AbstrDataCsv<FinalDataLine>(filepath)
    {
    }

    Finaldata<FinalDataLine>::~Finaldata()
    {
        m_file.close();
    }

    FinalDataLine Finaldata<FinalDataLine>::ParseCsvString(std::string raw)
    {
        FinalDataLine data;

        std::istringstream ss( raw );
        std::vector <std::string> record;

        while (ss)
        {
            std::string s;
            if (!getline( ss, s, m_separator )) break;
                record.push_back( s );
        }

        for(int i=0; i<record.size(); i++){
            switch (i)
            {
                case CsvHeader::LERP_LASER_TIME:
                    data.laser_time = std::stoul(record[i]);
                    break;
                case CsvHeader::LASER_ID:
                    data.laser_id = std::stoi(record[i]);
                    break;
                case CsvHeader::POINT_X:
                    data.x = std::stof(record[i]);
                    break;
                case CsvHeader::POINT_Y:
                    data.y = std::stof(record[i]);
                    break;
                case CsvHeader::POINT_Z:
                    data.z = std::stof(record[i]);
                    break;
                case CsvHeader::DISTANCE:
                    data.distance = std::stof(record[i]);
                    break;
                case CsvHeader::INTENSITY:
                    data.intensity = std::stoi(record[i]);
                    break;
                case CsvHeader::ROLL:
                    data.roll = std::stof(record[i]);
                    break;
                case CsvHeader::PITCH:
                    data.pitch = std::stof(record[i]);
                    break;
                case CsvHeader::YAW:
                    data.yaw = std::stof(record[i]);
                    break;
                case CsvHeader::N:
                    data.north = std::stod(record[i]);
                    break;
                case CsvHeader::E:
                    data.east = std::stod(record[i]);
                    break;
                case CsvHeader::D:
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
            }
            
        }

        return data;
    }
    

    std::string Finaldata<FinalDataLine>::MakeCsvString(FinalDataLine data)
    {
        std::string s="";
        s += std::to_string(data.laser_time) + m_separator;
        s += std::to_string(data.laser_id) + m_separator;  
        s += std::to_string(data.x) + m_separator; 
        s += std::to_string(data.y) + m_separator; 
        s += std::to_string(data.z) + m_separator; 
        s += std::to_string(data.distance) + m_separator; 
        s += std::to_string(data.intensity) + m_separator; 
        s += std::to_string(data.roll) + m_separator;
        s += std::to_string(data.pitch) + m_separator;
        s += std::to_string(data.yaw) + m_separator;
        s += std::to_string(data.north) + m_separator;
        s += std::to_string(data.east) + m_separator;       
        s += std::to_string(data.down) + m_separator;       
        s += std::to_string(data.latitude) + m_separator;   
        s += std::to_string(data.longitude) + m_separator;  
        s += std::to_string(data.attitude) ; 
        return s;
    }

    void Finaldata<FinalDataLine>::SetDefaultHeader()
    {
        m_header.clear();
        m_header.push_back("lerp_laser_time");
        m_header.push_back("laser_id");       
        m_header.push_back("point_x");       
        m_header.push_back("point_y");       
        m_header.push_back("point_z");      
        m_header.push_back("Distance");       
        m_header.push_back("Intensity");        
        m_header.push_back("Roll");      
        m_header.push_back("Pitch");       
        m_header.push_back("Yaw");        
        m_header.push_back("N");        
        m_header.push_back("E");       
        m_header.push_back("D");       
        m_header.push_back("Latitude");      
        m_header.push_back("Longitude");      
        m_header.push_back("Attitude");       
    }

}}