#pragma once
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>
#include "data_rider/Lines.h"

namespace drider {

    template <typename T>
    class AbstrDataCsv
    {
    public:
        AbstrDataCsv(){}
        //AbstrDataCsv(std::string filepath);

        virtual  ~AbstrDataCsv();

        virtual void Open(std::string filepath);
        virtual void Close();
        virtual void Reopen();

        virtual bool isOpen();
        virtual bool isEndFile();

        virtual std::vector<T> ReadCsvPart(int raw_count);
        virtual T ReadCsvRaw();

        virtual void WriteCsvRaw(T);

        virtual T ParseCsvString(std::string raw)=0;
        virtual std::string MakeCsvString(T)=0;

    protected:
        std::string m_filepath;
        std::fstream m_file;
        std::vector<std::string> m_header;

        //unsigned long int currnet_file_pos;
    };

    

}