// Generated by gencpp from file sbg_driver/SbgShipMotion.msg
// DO NOT EDIT!


#ifndef SBG_DRIVER_MESSAGE_SBGSHIPMOTION_H
#define SBG_DRIVER_MESSAGE_SBGSHIPMOTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>
#include "data_rider/sbg/sbgheaders/SbgShipMotionStatus.h"

namespace sbg_driver
{
template <class ContainerAllocator>
struct SbgShipMotion_
{
  typedef SbgShipMotion_<ContainerAllocator> Type;

  SbgShipMotion_()
    : header()
    , time_stamp(0)
    , heave_period(0)
    , ship_motion()
    , acceleration()
    , velocity()
    , status()  {
    }
  SbgShipMotion_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , time_stamp(0)
    , heave_period(0)
    , ship_motion(_alloc)
    , acceleration(_alloc)
    , velocity(_alloc)
    , status(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _time_stamp_type;
  _time_stamp_type time_stamp;

   typedef uint16_t _heave_period_type;
  _heave_period_type heave_period;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _ship_motion_type;
  _ship_motion_type ship_motion;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _acceleration_type;
  _acceleration_type acceleration;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _velocity_type;
  _velocity_type velocity;

   typedef  ::sbg_driver::SbgShipMotionStatus_<ContainerAllocator>  _status_type;
  _status_type status;





  typedef boost::shared_ptr< ::sbg_driver::SbgShipMotion_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sbg_driver::SbgShipMotion_<ContainerAllocator> const> ConstPtr;

}; // struct SbgShipMotion_

typedef ::sbg_driver::SbgShipMotion_<std::allocator<void> > SbgShipMotion;

typedef boost::shared_ptr< ::sbg_driver::SbgShipMotion > SbgShipMotionPtr;
typedef boost::shared_ptr< ::sbg_driver::SbgShipMotion const> SbgShipMotionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sbg_driver::SbgShipMotion_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sbg_driver

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sbg_driver': ['/home/lidar/scan_viz/src/sbg_driver/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sbg_driver::SbgShipMotion_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sbg_driver::SbgShipMotion_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sbg_driver::SbgShipMotion_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f76d2a0b5a6d09d258ebd78ee0233cd0";
  }

  static const char* value(const ::sbg_driver::SbgShipMotion_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf76d2a0b5a6d09d2ULL;
  static const uint64_t static_value2 = 0x58ebd78ee0233cd0ULL;
};

template<class ContainerAllocator>
struct DataType< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sbg_driver/SbgShipMotion";
  }

  static const char* value(const ::sbg_driver::SbgShipMotion_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# SBG Ellipse Messages\n\
Header header\n\
\n\
# Time since sensor is powered up μs \n\
uint32 time_stamp\n\
\n\
# Main heave period in seconds. s float 4 4\n\
uint16 heave_period\n\
\n\
# [Surge, Sway, Heave (positive down)] at main location (in m)\n\
# Note : Surge & Sway are not fulfilled\n\
geometry_msgs/Vector3 ship_motion\n\
\n\
# [Longitudinal, Lateral, Vertical (positive down)] acceleration (in m/s2)\n\
geometry_msgs/Vector3 acceleration\n\
\n\
# [Longitudinal, Lateral, Vertical (positive down)] velocity (in m/s)\n\
geometry_msgs/Vector3 velocity\n\
\n\
# Ship motion output status\n\
SbgShipMotionStatus status\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
================================================================================\n\
MSG: sbg_driver/SbgShipMotionStatus\n\
# SBG Ellipse Messages\n\
# SbgShipMotionStatus\n\
\n\
# True after heave convergence time.\n\
# False in following conditions:\n\
# - Turn occurred and no velocity aiding is available\n\
# - Heave reached higher/lower limits\n\
# - If a step is detected and filter has to re-converge\n\
# - If internal failure\n\
bool heave_valid\n\
\n\
# True if heave output is compensated for transient accelerations\n\
bool heave_vel_aided\n\
\n\
# True if the swell period is provided in this output\n\
bool period_available\n\
\n\
# True if the period returned is assumed to be valid or not.\n\
bool period_valid\n\
";
  }

  static const char* value(const ::sbg_driver::SbgShipMotion_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.time_stamp);
      stream.next(m.heave_period);
      stream.next(m.ship_motion);
      stream.next(m.acceleration);
      stream.next(m.velocity);
      stream.next(m.status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SbgShipMotion_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sbg_driver::SbgShipMotion_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sbg_driver::SbgShipMotion_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "time_stamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.time_stamp);
    s << indent << "heave_period: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.heave_period);
    s << indent << "ship_motion: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.ship_motion);
    s << indent << "acceleration: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.acceleration);
    s << indent << "velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.velocity);
    s << indent << "status: ";
    s << std::endl;
    Printer< ::sbg_driver::SbgShipMotionStatus_<ContainerAllocator> >::stream(s, indent + "  ", v.status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SBG_DRIVER_MESSAGE_SBGSHIPMOTION_H
