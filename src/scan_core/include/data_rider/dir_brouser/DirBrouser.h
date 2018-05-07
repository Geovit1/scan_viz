#pragma once

#include <iostream>
#include <ros/ros.h>
#include <ros/package.h>

namespace drider
{

    class DirBrouser
    {
    public:

        DirBrouser();
        virtual ~DirBrouser();
        

        static std::string FileDirectory();

        static std::string ConfigDirectory();
        static std::string ConfigDirectory(std::string filename);
        
        static std::string DataDirectory();
        static std::string DataDirectory(std::string filename);

    private:

    };

}
