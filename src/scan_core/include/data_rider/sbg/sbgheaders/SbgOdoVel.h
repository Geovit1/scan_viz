// Generated by gencpp from file sbg_driver/SbgOdoVel.msg
// DO NOT EDIT!


#ifndef SBG_DRIVER_MESSAGE_SBGODOVEL_H
#define SBG_DRIVER_MESSAGE_SBGODOVEL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace sbg_driver
{
template <class ContainerAllocator>
struct SbgOdoVel_
{
  typedef SbgOdoVel_<ContainerAllocator> Type;

  SbgOdoVel_()
    : header()
    , time_stamp(0)
    , status(false)
    , vel(0.0)  {
    }
  SbgOdoVel_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , time_stamp(0)
    , status(false)
    , vel(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _time_stamp_type;
  _time_stamp_type time_stamp;

   typedef uint8_t _status_type;
  _status_type status;

   typedef float _vel_type;
  _vel_type vel;





  typedef boost::shared_ptr< ::sbg_driver::SbgOdoVel_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sbg_driver::SbgOdoVel_<ContainerAllocator> const> ConstPtr;

}; // struct SbgOdoVel_

typedef ::sbg_driver::SbgOdoVel_<std::allocator<void> > SbgOdoVel;

typedef boost::shared_ptr< ::sbg_driver::SbgOdoVel > SbgOdoVelPtr;
typedef boost::shared_ptr< ::sbg_driver::SbgOdoVel const> SbgOdoVelConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sbg_driver::SbgOdoVel_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sbg_driver::SbgOdoVel_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sbg_driver::SbgOdoVel_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sbg_driver::SbgOdoVel_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ee0121dfc0d070625fdfebb3cc97e732";
  }

  static const char* value(const ::sbg_driver::SbgOdoVel_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xee0121dfc0d07062ULL;
  static const uint64_t static_value2 = 0x5fdfebb3cc97e732ULL;
};

template<class ContainerAllocator>
struct DataType< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sbg_driver/SbgOdoVel";
  }

  static const char* value(const ::sbg_driver::SbgOdoVel_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# SBG Ellipse Messages\n\
Header header\n\
\n\
# Time since sensor is powered up μs \n\
uint32 time_stamp\n\
\n\
# Real Measurement\n\
# True if this log comes from a real pulse measurement\n\
# False if it comes from a timeout\n\
bool status\n\
\n\
# Velocity in odometer direction (m/s)\n\
float32 vel\n\
\n\
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
";
  }

  static const char* value(const ::sbg_driver::SbgOdoVel_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.time_stamp);
      stream.next(m.status);
      stream.next(m.vel);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SbgOdoVel_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sbg_driver::SbgOdoVel_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sbg_driver::SbgOdoVel_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "time_stamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.time_stamp);
    s << indent << "status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.status);
    s << indent << "vel: ";
    Printer<float>::stream(s, indent + "  ", v.vel);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SBG_DRIVER_MESSAGE_SBGODOVEL_H
