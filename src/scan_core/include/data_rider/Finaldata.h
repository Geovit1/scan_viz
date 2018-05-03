#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>

namespace drider { namespace fd {

    class Finaldata
    {
    public:
        Finaldata(){}
        Finaldata(std::string filepath);
        virtual  ~Finaldata();

        enum CsvHeader
        {
            LERP_LASER_TIME,
            LASER_ID,
            POINT_X,
            POINT_Y,
            POINT_Z,
            DISTANCE,
            INTENSITY,
            ROLL,
            PITCH,
            YAW,
            N,
            E,
            D,
            LATITUDE,
            LONGITUDE,
            ATTITUDE
        };

        struct CsvLine
        {
            uint laser_time;
            char laser_id;
            
            float x;
            float y;
            float z;
            
            float distance;
            char intencity;

            float roll;
            float pitch;
            float yaw;

            double north;
            double east;
            double down;

            double latitude;
            double longitude;
            double attitude;

            void setLaserTime(std::string val);
            void setLaserId(std::string val);
            void setX(std::string val);
            void setY(std::string val);
            void setZ(std::string val);
            void setDistance(std::string val);
            void setIntensity(std::string val);
            void setRoll(std::string val);
            void setPitch(std::string val);
            void setYaw(std::string val);
            void setNorth(std::string val);
            void setEast(std::string val);
            void setDown(std::string val);
            void setLatitude(std::string val);
            void setLongitude(std::string val);
            void setAttitude(std::string val);
        };

        void Open(std::string filepath);
        void Close();
        void Reopen();

        std::vector<Finaldata::CsvLine> ReadCsv(int index, int count);

        Finaldata::CsvLine ParseCsvString(std::string raw);

    private:
        std::string m_filepath;
        std::ifstream m_file;
        unsigned long int currnet_file_pos;
    };

}}