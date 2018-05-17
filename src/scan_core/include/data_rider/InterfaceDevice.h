#pragma once

namespace drider
{
    class InterfaceDevice
    {
    public:
        InterfaceDevice(){}
        virtual ~InterfaceDevice();
    protected:
        /* data */
    };

    class InterfaceDeviceCamera: public InterfaceDevice
    {
    public:
        InterfaceDeviceData(){}
        virtual ~InterfaceDeviceData();
        
    protected:
        /* data */
    }

    class InterfaceDeviceData: public InterfaceDevice
    {
    public:
        InterfaceDeviceData(){}
        virtual ~InterfaceDeviceData();
        
        virtual static void Convert_BagToCsv(std::string in_bagfile, std::string out_csvfile)=0;
        virtual static void Convert_BagToBin(std::string in_bagfile, std::string out_binfile)=0;
        virtual static void Convert_CsvToBin(std::string in_bagfile, std::string out_binfile)=0;
        virtual static void Convert_BinToCsv(std::string in_bagfile, std::string out_binfile)=0;
    protected:
        /* data */
    }

    class InterfaceDeviceImu: public InterfaceDeviceData
    {
    public:
        InterfaceDeviceData(){}
        virtual ~InterfaceDeviceData();
        
    protected:
    }
    
    class InterfaceDeviceLidar: public InterfaceDeviceData
    {
    public:
        InterfaceDeviceData(){}
        virtual ~InterfaceDeviceData();
        
    protected:
        /* data */
    }

    class InterfaceDeviceGPS: public InterfaceDeviceData
    {
    public:
        InterfaceDeviceData(){}
        virtual ~InterfaceDeviceData();
        
        virtual void Trajectory_BagToKml(std::string in_bagfile, std::string out_binfile)=0;
        virtual void Trajectory_CsvToKml(std::string in_bagfile, std::string out_binfile)=0;
        virtual void Trajectory_BinToKml(std::string in_bagfile, std::string out_binfile)=0;
    protected:
        /* data */
    }

}
