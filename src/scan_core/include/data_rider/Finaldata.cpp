#include "data_rider/Finaldata.h"

namespace drider { namespace fd {

    void Finaldata::CsvLine::setLaserTime(std::string val){
        laser_time = std::stoul(val);
    }
    void Finaldata::CsvLine::setLaserId(std::string val){
        laser_id = std::stoi(val);
    }
    void Finaldata::CsvLine::setX(std::string val){
        x = std::stof(val);
    }
    void Finaldata::CsvLine::setY(std::string val){
        y = std::stof(val);
    }
    void Finaldata::CsvLine::setZ(std::string val){
        z = std::stof(val);
    }
    void Finaldata::CsvLine::setDistance(std::string val){
        distance = std::stof(val);
    }
    void Finaldata::CsvLine::setIntensity(std::string val){
        intencity = std::stoi(val);
    }
    void Finaldata::CsvLine::setRoll(std::string val){
        roll = std::stof(val);
    }
    void Finaldata::CsvLine::setPitch(std::string val){
        pitch = std::stof(val);
    }
    void Finaldata::CsvLine::setYaw(std::string val){
        yaw = std::stof(val);
    }
    void Finaldata::CsvLine::setNorth(std::string val){
        north = std::stod(val);
    }
    void Finaldata::CsvLine::setEast(std::string val){
        east = std::stod(val);
    }
    void Finaldata::CsvLine::setDown(std::string val){
        down = std::stod(val);
    }
    void Finaldata::CsvLine::setLatitude(std::string val){
        latitude = std::stod(val);
    }
    void Finaldata::CsvLine::setLongitude(std::string val){
        longitude = std::stod(val);
    }
    void Finaldata::CsvLine::setAttitude(std::string val){
        attitude = std::stod(val);
    }

    Finaldata::Finaldata(std::string filepath)
    {
        m_filepath = filepath;
        m_file.open(m_filepath);

        std::string header;
        std::getline(m_file,header);
    }

    Finaldata::~Finaldata()
    {
        m_file.close();
    }

    void Finaldata::Open(std::string filepath)
    {
        m_filepath = filepath;
        if(m_file.is_open())
        {
            m_file.close();
        }
        m_file.open(m_filepath);

        std::string header;
        std::getline(m_file,header);
    }

    void Finaldata::Close()
    {
        m_file.close();
    }

    void Finaldata::Reopen()
    {
        m_file.close();
        m_file.open(m_filepath);

        std::string header;
        std::getline(m_file,header);
    }

    std::vector<Finaldata::CsvLine> Finaldata::ReadCsv(int index, int count)
    {
        std::vector<Finaldata::CsvLine>    list;
        if(m_file.is_open())
        {
            for(int i=0; i<count; i++)
            {
                if(m_file.eof())
                {
                    Reopen();
                    break;
                }
                else {
                    std::string line,f;
                    std::getline(m_file,line);
                    list.push_back(ParseCsvString(line));
                }
            }
        }
        return list;
    }

    Finaldata::CsvLine Finaldata::ParseCsvString(std::string raw)
    {
        Finaldata::CsvLine data;

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
                    data.setLaserTime(record[i]);
                    break;
                case CsvHeader::LASER_ID:
                    data.setLaserId(record[i]);
                    break;
                case CsvHeader::POINT_X:
                    data.setX(record[i]);
                    break;
                case CsvHeader::POINT_Y:
                    data.setY(record[i]);
                    break;
                case CsvHeader::POINT_Z:
                    data.setZ(record[i]);
                    break;
                case CsvHeader::INTENSITY:
                    data.setIntensity(record[i]);
                    break;
                case CsvHeader::ROLL:
                    data.setRoll(record[i]);
                    break;
                case CsvHeader::PITCH:
                    data.setPitch(record[i]);
                    break;
                case CsvHeader::YAW:
                    data.setYaw(record[i]);
                    break;
                case CsvHeader::N:
                    data.setNorth(record[i]);
                    break;
                case CsvHeader::E:
                    data.setEast(record[i]);
                    break;
                case CsvHeader::D:
                    data.setDown(record[i]);
                    break;
                case CsvHeader::LATITUDE:
                    data.setLatitude(record[i]);
                    break;
                case CsvHeader::LONGITUDE:
                    data.setLongitude(record[i]);
                    break;
                case CsvHeader::ATTITUDE:
                    data.setAttitude(record[i]);
                    break;
            }
            
        }

        return data;
    }

}}