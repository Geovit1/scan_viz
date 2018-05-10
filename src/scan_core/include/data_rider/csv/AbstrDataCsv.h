#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>
#include "data_rider/csv/Lines.h"

namespace drider {  namespace csv {

    template <typename T>
    class AbstrDataCsv
    {
    public:
        AbstrDataCsv(){}
        AbstrDataCsv(std::string filepath);
        AbstrDataCsv(std::string filepath, char separator);

        virtual  ~AbstrDataCsv();

        virtual bool Open(std::string filepath);
        virtual bool Create(std::string filepath);
        virtual void Close();
        virtual void Reopen();

        virtual bool isOpen();
        virtual bool isEndFile();

        virtual std::vector<T> ReadCsvPart(int raw_count);
        virtual T ReadCsvRaw();

        virtual void WriteCsvRaw(T);

        virtual T ParseCsvString(std::string raw) = 0;
        virtual std::string MakeCsvString(T) = 0;

        virtual std::vector<std::string> getHeader(){ return m_header; }
    protected:
        std::string m_filepath;
        std::fstream m_file;
        
        char m_separator = ',';

        std::vector<std::string> m_header;
        virtual void setHeader(std::string);
        virtual void SetDefaultHeader() = 0;
        virtual std::string GetHeaderString();
        virtual void WriteHeader();
    };

    

}}