#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/tf.h>

#include "scan_core/godeye_retina/Sender.h"
#include "data_rider/dir_brouser/DirBrouser.h"

using namespace drider;

using namespace godeye_retina;


int main(int argc, char *argv[])
{

    std::cout<<"RETINA RUNNING"<<std::endl<<std::endl;

    ros::init(argc, argv, "trajectory_publisher");
    
    ros::NodeHandle n;

    std::string file = drider::DirBrouser::DataDirectory("sbg_enu.csv");

    Sender *sender = new Sender(n);
    AbstrGenerator *generator = new GeneratorTrajectory(file);

    sender->generator = generator;

    if(sender != nullptr){
        if(generator != nullptr){
            std::cout<<"RETINA Builded"<<std::endl<<std::endl;
        }
    }
    ros::Rate r(5.0);
    while(ros::ok())
    {
        ros::spinOnce();
        pcl::PointCloud<pcl::PointXYZI> cloud;
        ublas::vector<double> pos_xyz = ublas::vector<double>(3);
        ublas::vector<double> rpy = ublas::vector<double>(3);
        sender->GetNextBundle(cloud, pos_xyz, rpy);
        sender->PublishBundle(cloud, pos_xyz, rpy);

        ros::spinOnce();
        r.sleep();
    }

    return 0;
}