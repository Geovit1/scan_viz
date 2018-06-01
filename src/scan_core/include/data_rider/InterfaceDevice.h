#pragma once

namespace drider
{
    class InterfaceDevice
    {
    public:
    protected:
        /* data */
    };

    class InterfaceDeviceCamera: virtual public InterfaceDevice
    {
    public:
        
    protected:
        /* data */
    };

    class InterfaceDeviceData: virtual public InterfaceDevice
    {
    public:
        
        virtual void Convert_BagToCsv(std::string in_bagfile, std::string out_csvfile)=0;
        virtual void Convert_BagToBin(std::string in_bagfile, std::string out_binfile)=0;
        virtual void Convert_CsvToBin(std::string in_bagfile, std::string out_binfile)=0;
        virtual void Convert_BinToCsv(std::string in_bagfile, std::string out_binfile)=0;
    protected:
        /* data */
    };

    class InterfaceDeviceImu: virtual public InterfaceDeviceData
    {
    public:

        
    protected:
    };
    
    class InterfaceDeviceLidar: virtual public InterfaceDeviceData
    {
    public:
        
    protected:
        /* data */
    };

    class InterfaceDeviceGPS: virtual public InterfaceDeviceData
    {
    public:
        
        virtual void Convert_BagToTrajectory(std::string in_bagfile)=0;
        virtual void Convert_CsvToTrajectory(std::string in_csvfile)=0;
        virtual void Convert_BinToTrajectory(std::string in_binfile)=0;
    protected:
        /* data */
    };

}
