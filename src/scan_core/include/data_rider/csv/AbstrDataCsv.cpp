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

        std::ifstream ifile(m_filepath);//try open
        if(ifile.is_open())
        {
            ifile.close();
            return false; // file exist
        }
        else 
        {   
            m_file.open(m_filepath, std::fstream::in | std::fstream::out | std::fstream::app);
            SetDefaultHeader();
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
    int AbstrDataCsv<T>::ReadCsvPart(int raw_count, std::vector<T>& list)
    {
        int status=0;
        if(m_file.eof()){
            //Reopen();
            std::cout<<"End of file reached"<<std::endl;
            return Status::EOFILE;
        }

        list.clear(); 

        for(int i=0; i<raw_count; i++)
        {
            T raw;
            status = ReadCsvRaw(raw);

            if(status == Status::OPENED)
            {
                list.push_back(raw);
            }
            else if(status == Status::EOFILE)
                return status;
        }
        return status;

       /* if(m_file.is_open())
        {
            list.clear();
            for(int i=0; i<raw_count; i++)
            {
                if(std::getline(m_file, line).eof())
                {
                    //Reopen();
                    std::cout<<"End of file reached"<<std::endl;
                    return Status::EOFILE;
                }
                else 
                {
                    list.push_back(ParseCsvString(line));
                } 
            }
            return Status::OPENED;
        }
        return Status::CLOSED;*/
    }

    template<typename T>
    int AbstrDataCsv<T>::ReadCsvRaw(T &raw)
    {
        try
        {
            int ex =-1;

            if(m_file.is_open())
            {
                std::string line;

                try
                {
                    if(std::getline(m_file,line).eof())
                    {
                        std::cout<<"End of file reached"<<std::endl;
                        return Status::EOFILE;

                    }
                }
                catch(...)
                {
                    ex = ExceptionType::READING;
                }

                try 
                {
                    raw=ParseCsvString(line);
                }
                catch(...)
                {
                    ex = ExceptionType::PARSING;
                }

                if(ex != -1) throw ex;
                return Status::OPENED;            
            }
            return Status::CLOSED;
        }
        catch(int e)
        {
            TerminalExeptionMsg(e);
            return Status::ERROR;
        }
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

    template<typename T>
    void  AbstrDataCsv<T>::TerminalExeptionMsg(int e)
    {
        if(false)
        {
            switch(e)
            {
            case ExceptionType::PARSING:  
                std::cout<<"ERROR! Parsing csv string exception!"<< std::endl;  
                break;  
            case ExceptionType::READING:  
                std::cout<<"ERROR! Reading csv string exception!"<< std::endl;   
                break;  
            default:  
                std::cout<<"W T FUUUUUUUUUUCK !!!"<< std::endl; 
            }
        }
    }

    template class AbstrDataCsv<FinalDataLine>;
    template class AbstrDataCsv<SbgLine>;
    template class AbstrDataCsv<VelodyneLine>;
    template class AbstrDataCsv<TestDataLine>;
    template class AbstrDataCsv<PointTimeRefLine>;
}}