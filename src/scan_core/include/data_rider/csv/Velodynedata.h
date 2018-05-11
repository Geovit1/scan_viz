#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>

#include "data_rider/csv/AbstrDataCsv.h"


namespace drider { namespace csv {
    
    template<typename T> class Velodynedata: public AbstrDataCsv<T>
    {
        public:
            
            virtual T ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(T);
        private:
            virtual void SetDefaultHeader();
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
                /*ROS_TIMESTAMP_SEC,
                ROS_TIMESTAMP_NSEC,
                PACKET_STAMP_SEC,
                PACKET_STAMP_NSEC,*/
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
            virtual std::string MakeCsvString(VelodyneLine);
        private:
            virtual void SetDefaultHeader();
    };
   

}}