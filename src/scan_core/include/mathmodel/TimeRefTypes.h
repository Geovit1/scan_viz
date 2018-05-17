#pragma once

namespace mathmodel 
{
    struct Point 
    {
        unsigned int gps_time;
        
        float x;
        float y;
        float z;

    };

    struct Rotation 
    {
        unsigned int gps_time;

        float roll;
        float pitch;
        float yaw;
    };
}