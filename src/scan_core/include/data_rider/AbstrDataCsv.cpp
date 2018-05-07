#include "data_rider/AbstrDataCsv.h"

namespace drider {

    /*template<typename T>
    AbstrDataCsv<T>::AbstrDataCsv(std::string filepath)
    {
        m_filepath = filepath;
        m_file.open(m_filepath);

        std::string header;
        std::getline(m_file,header);
    }*/
    template<typename T>
    AbstrDataCsv<T>::~AbstrDataCsv()
    {
        m_file.close();
    }
    template<typename T>
    void AbstrDataCsv<T>::Open(std::string filepath)
    {
        m_filepath = filepath;
        if(m_file.is_open())
        {
            m_file.close();
        }
        m_file.open(m_filepath);

        std::string header;
        std::getline(m_file,header);

        std::cout<<"File opened"<<std::endl;
    }
    template<typename T>
    void AbstrDataCsv<T>::Close()
    {
        m_file.close();
    }
    template<typename T>
    void AbstrDataCsv<T>::Reopen()
    {
        m_file.close();
        m_file.open(m_filepath);

        std::string header;
        std::getline(m_file,header);
    }
    template<typename T>
    bool AbstrDataCsv<T>::isOpen()
    {
        if(m_file.is_open())
        {
            return true;
        } else return false;
    }

    template<typename T>
    std::vector<T> AbstrDataCsv<T>::ReadCsvPart(int raw_count)
    {
        if(m_file.eof()){
            Reopen();
            std::cout<<"end of file"<<std::endl;
        }

        std::vector<T> list;
        if(m_file.is_open())
        {
            for(int i=0; i<raw_count; i++)
            {
                if(m_file.eof())
                {
                    Reopen();
                    std::cout<<"end of file"<<std::endl;
                    break;
                }
                else {
                    std::string line,f;
                    std::getline(m_file,line);
                    list.push_back(ParseCsvString(line));
                }
            }
        }
        return list;
    }

    template<typename T>
   T AbstrDataCsv<T>::ReadCsvRaw()
    {
        if(m_file.eof())
        {
            Reopen();
        }
        T raw;
        if(m_file.is_open())
        {
            std::string line,f;
            std::getline(m_file,line);
            raw=ParseCsvString(line);
        }
        return raw;
    }

    template class AbstrDataCsv<FinalDataLine>;
    template class AbstrDataCsv<SbgLine>;
    template class AbstrDataCsv<VelodyneLine>;

}