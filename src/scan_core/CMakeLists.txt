cmake_minimum_required(VERSION 2.8.3)
project(scan_core)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS 
            cv_bridge 
            roscpp 
            std_msgs 
            image_geometry 
            sensor_msgs 
            image_transport 
            rosbag 
            pcl_conversions 
            pcl_ros
            angles
            nodelet
            roslib
            dynamic_reconfigure
            message_generation
            )

find_package(OpenCV REQUIRED)
#find_package(Boost 
#REQUIRED COMPONENTS 
#thread
#)
find_package(Boost REQUIRED)

################################################
## Declare ROS messages, services and actions ##
################################################


################################################
## Declare ROS dynamic reconfigure parameters ##
################################################


###################################
## catkin specific configuration ##
###################################


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES scan_core
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include 
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

## Add module DATA_RIDER ##############
add_library(data_rider
  include/data_rider/Finaldata.cpp
)

target_link_libraries(data_rider
  ${catkin_LIBRARIES}
)

## Add module MATH_MODEL ##############
add_library(mathmodel
  include/mathmodel/CoordinateSystems.cpp
)

target_link_libraries(mathmodel
  ${catkin_LIBRARIES}
  ${Boost_INCLUDE_DIRS}
)

## Add module GODEYE_RETINA ##############
# lib godeye_retina; executable retina
add_library(godeye_retina
  include/scan_core/godeye_retina/Sender.cpp
  include/scan_core/godeye_retina/Manager.cpp
  include/scan_core/godeye_retina/Generator.cpp
)

target_link_libraries(godeye_retina 
  ${catkin_LIBRARIES}
  ${Boost_INCLUDE_DIRS}
)

add_executable(retina 
  src/godeye_retina/retina.cpp
)

target_link_libraries(retina godeye_retina data_rider mathmodel
  ${catkin_LIBRARIES}
  ${Boost_INCLUDE_DIRS}
)
#########################################

#############
## Install ##
#############


#############
## Testing ##
#############
