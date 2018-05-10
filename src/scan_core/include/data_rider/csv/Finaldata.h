#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>

#include "data_rider/csv/AbstrDataCsv.h"

namespace drider { namespace csv {
    
    template<typename T> class Finaldata: public AbstrDataCsv<T>
    {
        public:
            
            virtual T ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(T);
        private:
            virtual void SetDefaultHeader();
    };


    template<> class Finaldata<FinalDataLine> : public AbstrDataCsv<FinalDataLine>
    {
        public:
            Finaldata(): AbstrDataCsv<FinalDataLine>() {}
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

            virtual FinalDataLine ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(FinalDataLine);
        private:
            virtual void SetDefaultHeader();
    };

    

}}