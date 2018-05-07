
#include "DirBrouser.h"


namespace drider
{

    std::string DirBrouser::FileDirectory()
    {
        return ros::package::getPath("scan_core") + "/scan_core_files/";
    }

    std::string DirBrouser::ConfigDirectory()
    {
        return FileDirectory() + "config/";
    }

    std::string DirBrouser::ConfigDirectory(std::string filename)
    {
        return FileDirectory() + "config/" + filename;
    }

    std::string DirBrouser::DataDirectory()
    {
        return FileDirectory() + "data/";
    }

    std::string DirBrouser::DataDirectory(std::string filename)
    {
        return FileDirectory() + "data/" + filename;
    }
    

}