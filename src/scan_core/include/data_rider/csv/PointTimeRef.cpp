#include "data_rider/csv/PointTimeRef.h"

namespace drider { namespace csv {
  
    PointTimeRef<PointTimeRefLine>::PointTimeRef(std::string filepath)
                        : AbstrDataCsv<PointTimeRefLine>(filepath)
    {
    }

    PointTimeRef<PointTimeRefLine>::~PointTimeRef()
    {
        m_file.close();
    }

    PointTimeRefLine PointTimeRef<PointTimeRefLine>::ParseCsvString(std::string raw)
    {
        PointTimeRefLine data;

        std::istringstream ss( raw );
        std::vector <std::string> record;

        while (ss)
        {
            std::string s;
            if (!getline( ss, s, m_separator)) break;
                record.push_back( s );
        }

        for(int i=0; i<record.size(); i++){
            switch (i)
            {
                case CsvHeader::TIME_STAMP:
                    data.time = std::stoul(record[i]);
                    break;
                case CsvHeader::POINT_X:
                    data.x = std::stod(record[i]);
                    break;
                case CsvHeader::POINT_Y:
                    data.y = std::stod(record[i]);
                    break;
                case CsvHeader::POINT_Z:
                    data.z = std::stod(record[i]);
                    break;
            } 
        }

        return data;
    }

    std::string PointTimeRef<PointTimeRefLine>::MakeCsvString(PointTimeRefLine data)
    {
        std::string s="";

        s += std::to_string(data.time) + m_separator; 
        s += std::to_string(data.x) + m_separator;
        s += std::to_string(data.y) + m_separator;
        s += std::to_string(data.z);  
        
        return s;
    }

    void PointTimeRef<PointTimeRefLine>::SetDefaultHeader()
    {
        m_header.clear();
        m_header.push_back("gps_time");
        m_header.push_back("x"); 
        m_header.push_back("y");
        m_header.push_back("z");
    }

}}