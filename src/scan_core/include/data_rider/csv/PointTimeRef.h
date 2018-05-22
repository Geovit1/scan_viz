#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>

#include "data_rider/csv/AbstrDataCsv.h"


namespace drider { namespace csv {
    
    template<typename T> class PointTimeRef: public AbstrDataCsv<T>
    {
        public:
            
            virtual T ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(T);
        private:
            virtual void SetDefaultHeader();
    };


    template<> class PointTimeRef<PointTimeRefLine> : public AbstrDataCsv<PointTimeRefLine>
    {
        public:
            PointTimeRef(): AbstrDataCsv<PointTimeRefLine>() {}
            PointTimeRef(std::string filepath);
            virtual  ~PointTimeRef();

            enum CsvHeader
            {
                TIME_STAMP,
                POINT_X,
                POINT_Y,
                POINT_Z
            };

            virtual PointTimeRefLine ParseCsvString(std::string raw);
            virtual std::string MakeCsvString(PointTimeRefLine);
        private:
            virtual void SetDefaultHeader();
    };

    

}}
