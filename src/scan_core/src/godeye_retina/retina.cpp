#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <tf/tf.h>
#include "scan_core/godeye_retina/Sender.h"
#include "data_rider/Finaldata.h"

using namespace drider::fd;

std::string f = "/home/robot/hhh/csvv/velodyne_sbg.csv";

int main(int argc, char *argv[])
{
    //ros::init(argc, argv, "trajectory");
    /* code for main function */
    Finaldata csvv;
    csvv.Open(f);
    std::vector<Finaldata::CsvLine> list = csvv.ReadCsv(0,3);

    for(int i=0; i<list.size(); i++)
    {

    }

    csvv.ReadCsv(0,3);
    csvv.Close();
    return 0;
}