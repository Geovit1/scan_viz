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

    struct VelodyneLine
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
