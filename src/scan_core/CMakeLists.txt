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
            
            message_runtime

            #velodyne_msgs
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
  #CATKIN_DEPENDS ${${PROJECT_NAME}_CATKIN_DEPS}
  #INCLUDE_DIRS include
  #LIBRARIES velodyne_rawdata
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include ${catkin_INCLUDE_DIRS}
  include 
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${GSTREAMER_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${YAML_CPP_LIBRARIES}
)

if(NOT ${YAML_CPP_VERSION} VERSION_LESS "0.5")
add_definitions(-DHAVE_NEW_YAMLCPP)
endif(NOT ${YAML_CPP_VERSION} VERSION_LESS "0.5")


## Add module DATA_RIDER ##############
add_library(data_rider
  #include/data_rider/InterfaceDevice.h
  #csv sublib
  include/data_rider/csv/Velodynedata.cpp
  include/data_rider/csv/Sbgdata.cpp
 #include/data_rider/csv/Lines.cpp
  include/data_rider/csv/AbstrDataCsv.cpp
  include/data_rider/csv/Finaldata.cpp
  include/data_rider/csv/Testdata.cpp

  #dir brouser sublib
  include/data_rider/dir_brouser/DirBrouser.cpp

  #velodyne sublib
  include/data_rider/velodyne/VelodataConverter.cpp
  include/data_rider/velodyne/ImuUnpacker.cpp
  include/data_rider/velodyne/DataUnpacker.cpp
  include/data_rider/velodyne/Calibrator.cpp
)

target_link_libraries(data_rider
  ${catkin_LIBRARIES}
  ${YAML_CPP_LIBRARIES}
)

## Add module MATH_MODEL ##############
add_library(mathmodel
  include/mathmodel/Matrices.cpp
  include/mathmodel/Rotations.cpp
  include/mathmodel/Interpolation.cpp
  include/mathmodel/CoordinateSystems.cpp
  include/mathmodel/TimeRefTypes.cpp
  
)

target_link_libraries(mathmodel
  ${catkin_LIBRARIES}
  ${Boost_INCLUDE_DIRS}
)

## Add module GODEYE_RETINA ##############
# lib godeye_retina; executable retina
add_library(godeye_retina
  include/scan_core/godeye_retina/Pathway.cpp
  include/scan_core/godeye_retina/Sender.cpp
  include/scan_core/godeye_retina/Manager.cpp
  include/scan_core/godeye_retina/Generator.cpp
)

target_link_libraries(godeye_retina data_rider
  ${catkin_LIBRARIES}
  ${Boost_INCLUDE_DIRS}
)

add_executable(retina 
  src/godeye_retina/retina.cpp
)


target_link_libraries(retina godeye_retina mathmodel
  ${catkin_LIBRARIES}
  ${Boost_INCLUDE_DIRS}
)
#########################################

#############
## Install ##
#############

#install(DIRECTORY include/${PROJECT_NAME}/
#        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
#############
## Testing ##
#############


add_executable(test_csv
  src/test_csv.cpp
)

add_executable(test_math
  src/test_math.cpp
)

#add_dependencies(test ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(test_csv data_rider
  ${catkin_LIBRARIES}
)

target_link_libraries(test_math data_rider mathmodel
  ${catkin_LIBRARIES})