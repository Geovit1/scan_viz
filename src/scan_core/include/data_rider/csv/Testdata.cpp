#include "data_rider/csv/Testdata.h"

namespace drider { namespace csv {
  
    Testdata<TestDataLine>::Testdata(std::string filepath, char sep)
                        : AbstrDataCsv<TestDataLine>(filepath, sep)
    {
    }

    Testdata<TestDataLine>::~Testdata()
    {
        m_file.close();
    }

    TestDataLine Testdata<TestDataLine>::ParseCsvString(std::string raw)
    {
        TestDataLine data;

        std::istringstream ss( raw );
        std::vector <std::string> record;

        while (ss)
        {
            std::string s;
            if (!getline( ss, s, m_separator)) break;
                record.push_back(s);
        }

        for(int i=0; i<record.size(); i++)
        {
            switch (i)
            {
                case CsvHeader::TIMESTAMP:
                    data.timestamp = std::stoul(record[i]);
                    break;
                case CsvHeader::FLAG:
                    data.flag = std::stoi(record[i]);
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

    std::string Testdata<TestDataLine>::MakeCsvString(TestDataLine data)
    {
        std::string s="";
        s += std::to_string(data.timestamp) + m_separator;
        s += std::to_string(data.flag) + m_separator;
        s += std::to_string(data.x) + m_separator;
        s += std::to_string(data.y) + m_separator;
        s += std::to_string(data.z);
        return s;
    }

    void Testdata<TestDataLine>::SetDefaultHeader()
    {
        m_header.clear();
        m_header.push_back("timestamp");
        m_header.push_back("flag");
        m_header.push_back("x");       
        m_header.push_back("y");
        m_header.push_back("z");           
        
    }

}}