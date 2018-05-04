#include "data_rider/Finaldata.h"

namespace drider {
  
    Finaldata<FinalDataLine>::Finaldata(std::string filepath): AbstrDataCsv<FinalDataLine>()
    {
        m_filepath = filepath;
        m_file.open(m_filepath);

        std::string header;
        std::getline(m_file,header);
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
            if (!getline( ss, s, ',' )) break;
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
                    data.intencity = std::stoi(record[i]);
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
    template class AbstrDataCsv<FinalDataLine>;

}