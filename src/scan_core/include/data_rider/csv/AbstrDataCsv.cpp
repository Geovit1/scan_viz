#include "data_rider/csv/AbstrDataCsv.h"

namespace drider { namespace csv {


    template<typename T>
    AbstrDataCsv<T>::AbstrDataCsv(std::string filepath)
    {
        Open(filepath);
    }

    template<typename T>
    AbstrDataCsv<T>::AbstrDataCsv(std::string filepath, char separator)
    {
        m_filepath = filepath;
        m_file.open(m_filepath);

        m_separator = separator;
        Open(filepath);

        std::string header;
        std::getline(m_file,header);
        setHeader(header);
    }

    template<typename T>
    AbstrDataCsv<T>::~AbstrDataCsv()
    {
        m_file.close();
    }

    template<typename T>
    bool AbstrDataCsv<T>::Open(std::string filepath)
    {
        m_filepath = filepath;
        if(m_file.is_open())//if it opened the other file - close
        {
            m_file.close();
        }

        m_file.open(m_filepath);//open new
        if(m_file.is_open())
        {
            std::string header;
            std::getline(m_file,header);
            setHeader(header);
            return true;
        }
        else 
        {
            return false;
        }
        
    }

    template<typename T>
    bool AbstrDataCsv<T>::Create(std::string filepath)
    {
        m_filepath = filepath;
        if(m_file.is_open())//if it opened the other file - close
        {
            m_file.close();
        }

        m_file.open(m_filepath, std::fstream::in);//try open
        if(m_file.is_open())
        {
            return false; // file exist
        }
        else 
        {
            m_file.open(m_filepath, std::fstream::in | std::fstream::out | std::fstream::app);
            WriteHeader();
            return true;
        }
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
    bool AbstrDataCsv<T>::isEndFile()
    {
        if(m_file.eof())
        {
            return true;
        } else return false;
    }

    template<typename T>
    std::vector<T> AbstrDataCsv<T>::ReadCsvPart(int raw_count)
    {
        if(m_file.eof()){
            Reopen();
            std::cout<<"End of file reached"<<std::endl;
        }

        std::vector<T> list;
        if(m_file.is_open())
        {
            for(int i=0; i<raw_count; i++)
            {
                if(m_file.eof())
                {
                    Reopen();
                    std::cout<<"End of file reached"<<std::endl;
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


    template<typename T>
    void  AbstrDataCsv<T>::WriteCsvRaw(T a)
    {
        m_file << MakeCsvString(a) << std::endl;
    }

    template<typename T>
    void  AbstrDataCsv<T>::WriteHeader()
    {
        m_file << GetHeaderString() << std::endl;
    }

    template<typename T>
    void  AbstrDataCsv<T>::setHeader(std::string header)
    {
        std::istringstream ss( header );
        m_header.clear();

        while (ss)
        {
            std::string s;
            if (!getline( ss, s, m_separator )) break;
                m_header.push_back( s );
        }
    }

    template<typename T>
    std::string  AbstrDataCsv<T>::GetHeaderString()
    {
        std::string s_header = "";
        for(int i=0; i < m_header.size() - 1 ; i++)
        {
            s_header += m_header[i] + m_separator;
        }
        s_header += m_header[ m_header.size() - 1 ];

        return s_header;
    }


    template class AbstrDataCsv<FinalDataLine>;
    template class AbstrDataCsv<SbgLine>;
    template class AbstrDataCsv<VelodyneLine>;

}}