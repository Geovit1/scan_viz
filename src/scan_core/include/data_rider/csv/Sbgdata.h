#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>

#include "data_rider/csv/AbstrDataCsv.h"


namespace drider { namespace csv {
    
    template<typename T> class Sbgdata: public AbstrDataCsv<T>
    {
        public:
            
            virtual T ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(T);
        private:
            virtual void SetDefaultHeader();
    };


    template<> class Sbgdata<SbgLine> : public AbstrDataCsv<SbgLine>
    {
        public:
            Sbgdata(): AbstrDataCsv<SbgLine>() {}
            Sbgdata(std::string filepath, char separator);
            virtual  ~Sbgdata();
            //setSeparator(char sep);

            enum CsvHeader
            {
                ROS_TIMESTAMP,
                YEAR,
                MONTH,
                DAY,
                HOUR,
                MINUTE,
                SECOND,
                INTENSITY,
                UTC_NANOSECOND,
                GPS_WEEK,
                CLOCK_STABLE,
                CLOCK_STATUS,
                CLOCK_UTC_SYNC,
                CLOCK_UTC_STATUS,
                ROLL,
                PITCH,
                YAW,
                NORTH,
                EAST,
                DOWN,
                LATITUDE,
                LONGITUDE,
                ATTITUDE,
                UNDULATION,
                SOLUTION_MODE
            };


            //virtual std::vector<FinalDataLine> ReadCsv(int index, int raw_count);
            //virtual FinalDataLine ReadCsvRaw();

            virtual SbgLine ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(SbgLine);
        private:
            virtual void SetDefaultHeader();
    };

    

}}