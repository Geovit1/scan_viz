#pragma once

#include "scan_core/godeye_retina/Sender.h"
#include "data_rider/dir_brouser/DirBrouser.h"

namespace godeye_retina
{
    class Manager
    {
    public:
        Manager(ros::NodeHandle &n);
        ~Manager();
        int count=0;
        void LifeCycle();
    private:
        Sender *sender;
        AbstrGenerator *generator;
    };
    
}
