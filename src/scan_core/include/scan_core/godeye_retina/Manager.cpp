
#include "scan_core/godeye_retina/Manager.h"

namespace godeye_retina
{
    Manager::Manager(ros::NodeHandle &n)
    {
        std::string file = drider::DirBrouser::DataDirectory("velodyne_sbg.csv");

        sender = new Sender(n);
        generator = new GeneratorFinalData(file);

        sender->generator = generator;

        if(sender != nullptr){
            if(generator != nullptr){
                std::cout<<"Builded"<<std::endl;
            }
        }

    }
    Manager::~Manager()
    {
    }

    void Manager::LifeCycle()
    {
        ros::Rate r(5.0);

        while(ros::ok())
        {
            ros::spinOnce();

            pcl::PointCloud<pcl::PointXYZRGB> cloud;
            ublas::vector<double> pos_xyz = ublas::vector<double>(3);
            ublas::vector<double> rpy = ublas::vector<double>(3);
            sender->GetNextBundle(cloud, pos_xyz, rpy);
            std::cout<<pos_xyz[0]<<" "<<pos_xyz[1]<<" "<<pos_xyz[2]<<std::endl;
            std::cout<<rpy[0]<<" "<<rpy[1]<<" "<<rpy[2]<<std::endl;
            sender->PublishBundle(cloud, pos_xyz, rpy);
            
            std::string command;
            std::cout<<"next"<<std::endl;

            ros::spinOnce();
            r.sleep();
        }
        /*
        while(true)
        {
            pcl::PointCloud<pcl::PointXYZRGB> cloud;
            ublas::vector<double> pos_xyz = ublas::vector<double>(3);
            ublas::vector<double> rpy = ublas::vector<double>(3);
            sender->GetNextBundle(cloud, pos_xyz, rpy);
            sender->PublishBundle(cloud, pos_xyz, rpy);
            
            std::string command;
            std::cout<<"next"<<std::endl;
            std::cin>> command;
        } */
    }
    
}