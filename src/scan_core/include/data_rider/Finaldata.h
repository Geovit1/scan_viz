#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>
#include "data_rider/Lines.h"
#include "data_rider/AbstrDataCsv.h"


namespace drider {
    
    template<typename T> class Finaldata: public AbstrDataCsv<T>
    {
        public:
            
            virtual T ParseCsvString(std::string raw);
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


            //virtual std::vector<FinalDataLine> ReadCsv(int index, int raw_count);
            //virtual FinalDataLine ReadCsvRaw();

            virtual FinalDataLine ParseCsvString(std::string raw);

        private:
            //unsigned long int currnet_file_pos;
    };

    

}