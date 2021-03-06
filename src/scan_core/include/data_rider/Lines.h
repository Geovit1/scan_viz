#pragma once

namespace drider 
{
    
    struct FinalDataLine
    {    
        uint laser_time;
        char laser_id;
            
        float x;
        float y;
        float z;
            
        float distance;
        char intencity;

        float roll;
        float pitch;
        float yaw;

        double north;
        double east;
        double down;

        double latitude;
        double longitude;
        double attitude;
    };


    struct SbgLine
    {
        
            
        uint ros_timestamp;
        unsigned short int year;
        char month;
        char day;
        char hour;
        char minute;
        char second;

        uint utc_nanosecond;
        uint gps_week;
        bool clock_stable;
        bool clock_status;
        bool clock_utc_sync;
        bool clock_utc_status;
        
        double roll;
        double pitch;
        double yaw;

        double north;
        double east;
        double down;

        double latitude;
        double longitude;
        double attitude;

        unsigned short int undulation;
        char solution_mode;
    };

    struct VelodyneLine
    {       
        uint ros_timestamp;
        uint packet_stamp;
        
        char laser_id ;
        uint gps_time_toh;

        uint lerp_laser_time;
        double x;
        double y;
        double z;
            
        double distance;
        char intensity;
        
    };

    struct ZFLine
    {
            
        uint laser_time;
        char laser_id;
            
        float x;
        float y;
        float z;
            
        float distance;
        char intencity;

        float roll;
        float pitch;
        float yaw;

        double north;
        double east;
        double down;

        double latitude;
        double longitude;
        double attitude;
    };
}
