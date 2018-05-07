#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>
#include "data_rider/Lines.h"
#include "data_rider/AbstrDataCsv.h"


namespace drider {
    
    template<typename T> class Velodynedata: public AbstrDataCsv<T>
    {
        public:
            
            virtual T ParseCsvString(std::string raw);
    };


    template<> class Velodynedata<VelodyneLine> : public AbstrDataCsv<VelodyneLine>
    {
        public:
            Velodynedata(): AbstrDataCsv<VelodyneLine>() {}
            Velodynedata(std::string filepath, char sep);
            virtual  ~Velodynedata();
            //setSeparator(char sep);

            enum CsvHeader
            {
                ROS_TIMESTAMP,
                PACKET_STAMP,
                LASER_ID,
                GPS_TIME_TOH,
                LERP_LASER_TIME,
                POINT_X,
                POINT_Y,
                POINT_Z,
                DISTANCE,
                INTENSITY
            };


            //virtual std::vector<FinalDataLine> ReadCsv(int index, int raw_count);
            //virtual FinalDataLine ReadCsvRaw();

            virtual VelodyneLine ParseCsvString(std::string raw);

        private:
            //unsigned long int currnet_file_pos;
            char separator;
    };

    

}