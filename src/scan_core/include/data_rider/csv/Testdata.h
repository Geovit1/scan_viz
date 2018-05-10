#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>

#include "data_rider/csv/AbstrDataCsv.h"


namespace drider { namespace csv {

    template<typename T> class Testdata: public AbstrDataCsv<T>
    {
        public:
            
            virtual T ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(T);
        private:
            virtual void SetDefaultHeader();
    };


    template<> class Testdata<TestDataLine> : public AbstrDataCsv<TestDataLine>
    {
        public:
            Testdata(): AbstrDataCsv<TestDataLine>() {}
            Testdata(std::string filepath, char separator);
            virtual  ~Testdata();

            enum CsvHeader
            {
                TIMESTAMP,
                FLAG,
                POINT_X,
                POINT_Y,
                POINT_Z
            };

            virtual TestDataLine ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(TestDataLine);
        private:
            virtual void SetDefaultHeader();
    };

}}    