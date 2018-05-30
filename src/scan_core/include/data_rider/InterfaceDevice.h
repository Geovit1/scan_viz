#pragma once

namespace drider
{
    class InterfaceDevice
    {
    public:
        InterfaceDevice(){}
        virtual ~InterfaceDevice()=0;
    protected:
        /* data */
    };

    class InterfaceDeviceCamera: public InterfaceDevice
    {
    public:
        InterfaceDeviceCamera(){}
        virtual ~InterfaceDeviceCamera()=0;
        
    protected:
        /* data */
    };

    class InterfaceDeviceData: public InterfaceDevice
    {
    public:
        InterfaceDeviceData(){}
        virtual ~InterfaceDeviceData();
        
        virtual void Convert_BagToCsv(std::string in_bagfile, std::string out_csvfile)=0;
        virtual void Convert_BagToBin(std::string in_bagfile, std::string out_binfile)=0;
        virtual void Convert_CsvToBin(std::string in_bagfile, std::string out_binfile)=0;
        virtual void Convert_BinToCsv(std::string in_bagfile, std::string out_binfile)=0;
    protected:
        /* data */
    };

    class InterfaceDeviceImu: public InterfaceDeviceData
    {
    public:
        InterfaceDeviceImu(){}
        virtual ~InterfaceDeviceImu();
        
    protected:
    };
    
    class InterfaceDeviceLidar: public InterfaceDeviceData
    {
    public:
        InterfaceDeviceLidar(){}
        virtual ~InterfaceDeviceLidar();
        
    protected:
        /* data */
    };

    class InterfaceDeviceGPS: public InterfaceDeviceData
    {
    public:
        InterfaceDeviceGPS(){}
        virtual ~InterfaceDeviceGPS();
        
        virtual void Convert_BagToTrajectory(std::string in_bagfile)=0;
        virtual void Convert_CsvToTrajectory(std::string in_csvfile)=0;
        virtual void Convert_BinToTrajectory(std::string in_binfile)=0;
    protected:
        /* data */
    };

}
