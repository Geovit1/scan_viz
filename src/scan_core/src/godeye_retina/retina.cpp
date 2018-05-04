#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/tf.h>
#include "scan_core/godeye_retina/Manager.h"
//#include "data_rider/Finaldata.h"

using namespace drider;

using namespace godeye_retina;


std::string f = "/home/robot/hhh/csvv/velodyne_sbg.csv";

int main(int argc, char *argv[])
{
    std::cout<<"run"<<std::endl;

    ros::init(argc, argv, "laser_scan_publisher");
    
    ros::NodeHandle n;

    Manager* man = new Manager(n);
    man->LifeCycle();


    //ros::init(argc, argv, "trajectory");
    /* code for main function */
    /*Finaldata csvv;
    csvv.Open(f);
    std::vector<Finaldata::CsvLine> list = csvv.ReadCsv(0,3);

    for(int i=0; i<list.size(); i++)
    {

    }

    csvv.ReadCsv(0,3);
    csvv.Close();*/
    return 0;
}