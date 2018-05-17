#include "scan_core/godeye_retina/Sender.h"

namespace godeye_retina
{
    Sender::Sender(ros::NodeHandle &n)
    {
        odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
        pathway_pub = n.advertise<nav_msgs::Path>("way", 50);
        pointcloud_pub = n.advertise<pcl::PointCloud<pcl::PointXYZI>>("point_cloud", 40);

        m_current_time = ros::Time::now();
        m_last_time = ros::Time::now();
    }

    void Sender::GetNextBundle(pcl::PointCloud<pcl::PointXYZI> &cloud,
                            ublas::vector<double> &pos_xyz, ublas::vector<double> &rpy)
    {
        if(generator != nullptr)
        {
            generator->NextData(cloud, pos_xyz, rpy);
            std::cout<<"Sender::GetNextBundle"<<std::endl;
        }
    }


    void Sender::ClearPathway()
    {
        pathway.poses.clear();
    }

    void Sender::PublishBundle(pcl::PointCloud<pcl::PointXYZI> &cloud,
                            ublas::vector<double> &pos_xyz, ublas::vector<double> &rpy)
    {
       // ros::spinOnce();               // check for incoming messages
        m_current_time = ros::Time::now();

        double vx = 0.1;
        double vy = -0.1;
        double vth = 0.1;
        //compute odometry in a typical way given the velocities of the robot
        double dt = (m_current_time - m_last_time).toSec();
        double delta_x = (vx * cos(rpy[2]) - vy * sin(rpy[2])) * dt;
        double delta_y = (vx * sin(rpy[2]) + vy * cos(rpy[2])) * dt;
        double delta_th = vth * dt;
        //yaw += 0.1;//delta_th;

        //since all odometry is 6DOF we'll need a quaternion created from yaw
        geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromRollPitchYaw(rpy[0], rpy[1], rpy[2]);

        //first, we'll publish the transform over tf
        geometry_msgs::TransformStamped odom_trans;
        odom_trans.header.stamp = m_current_time;
        odom_trans.header.frame_id = "odom";
        odom_trans.child_frame_id = "base_link";

        odom_trans.transform.translation.x = pos_xyz[0];
        odom_trans.transform.translation.y = pos_xyz[1];
        odom_trans.transform.translation.z = pos_xyz[2];
        odom_trans.transform.rotation = odom_quat;


        pathway.header.frame_id = "odom";
        geometry_msgs::PoseStamped ps;
        ps.header.frame_id = "base_link";

        ps.header.frame_id = "base_link";
        ps.pose.position.x = pos_xyz[0];
        ps.pose.position.y = pos_xyz[1];
        ps.pose.position.z = pos_xyz[2];
        ps.pose.orientation = odom_quat;

        pathway.poses.push_back(ps);

        std::cout<<"way_pub.publish(m_msg)"<<std::endl;
        pathway_pub.publish(pathway);

        //send the transform
        m_odom_broadcaster.sendTransform(odom_trans);

        //next, we'll publish the odometry message over ROS
        nav_msgs::Odometry odom;
        odom.header.stamp = m_current_time;
        odom.header.frame_id = "odom";

        //set the position
        odom.pose.pose.position.x = pos_xyz[0];
        odom.pose.pose.position.y = pos_xyz[1];
        odom.pose.pose.position.z = pos_xyz[2];
        odom.pose.pose.orientation = odom_quat;

        //set the velocity
        odom.child_frame_id = "base_link";
        odom.twist.twist.linear.x = vx;
        odom.twist.twist.linear.y = vy;
        odom.twist.twist.angular.z = vth;

        //publish the message
        std::cout<<"odom_pub.publish(odom)"<<std::endl;
        odom_pub.publish(odom);

        m_last_time = m_current_time;
    }

}