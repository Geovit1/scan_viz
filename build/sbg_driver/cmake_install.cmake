# Install script for directory: /home/zf/scan_viz/src/sbg_driver

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/zf/scan_viz/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sbg_driver/msg" TYPE FILE FILES
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgGpsVelStatus.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgGpsPosStatus.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgMagStatus.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgShipMotionStatus.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgUtcTimeStatus.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgEkfEuler.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgGpsPos.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgMag.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgStatusCom.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgEkfNav.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgGpsRaw.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgOdoVel.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgStatusGeneral.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgEkfQuat.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgGpsVel.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgPressure.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgStatus.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgEvent.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgImuStatus.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgImuData.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgShipMotion.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgUtcTime.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgGpsHdt.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgMagCalib.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgStatusAiding.msg"
    "/home/zf/scan_viz/src/sbg_driver/msg/SbgEkfStatus.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sbg_driver/cmake" TYPE FILE FILES "/home/zf/scan_viz/build/sbg_driver/catkin_generated/installspace/sbg_driver-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/zf/scan_viz/devel/include/sbg_driver")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/zf/scan_viz/devel/share/roseus/ros/sbg_driver")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/zf/scan_viz/devel/share/common-lisp/ros/sbg_driver")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/zf/scan_viz/devel/share/gennodejs/ros/sbg_driver")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/zf/scan_viz/devel/lib/python2.7/dist-packages/sbg_driver")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/zf/scan_viz/devel/lib/python2.7/dist-packages/sbg_driver")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/zf/scan_viz/build/sbg_driver/catkin_generated/installspace/sbg_driver.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sbg_driver/cmake" TYPE FILE FILES "/home/zf/scan_viz/build/sbg_driver/catkin_generated/installspace/sbg_driver-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sbg_driver/cmake" TYPE FILE FILES
    "/home/zf/scan_viz/build/sbg_driver/catkin_generated/installspace/sbg_driverConfig.cmake"
    "/home/zf/scan_viz/build/sbg_driver/catkin_generated/installspace/sbg_driverConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sbg_driver" TYPE FILE FILES "/home/zf/scan_viz/src/sbg_driver/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/sbg_driver" TYPE EXECUTABLE FILES "/home/zf/scan_viz/devel/lib/sbg_driver/ellipse")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse"
         OLD_RPATH "/opt/ros/kinetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse_mag" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse_mag")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse_mag"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/sbg_driver" TYPE EXECUTABLE FILES "/home/zf/scan_viz/devel/lib/sbg_driver/ellipse_mag")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse_mag" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse_mag")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse_mag"
         OLD_RPATH "/opt/ros/kinetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/sbg_driver/ellipse_mag")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/sbg_driver" TYPE DIRECTORY FILES "/home/zf/scan_viz/src/sbg_driver/include/sbg_driver/" FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/\\.svn$" EXCLUDE REGEX "/\\.git$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sbg_driver/launch" TYPE DIRECTORY FILES "/home/zf/scan_viz/src/sbg_driver/launch/" REGEX "/\\.git$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/sbg_driver/config" TYPE DIRECTORY FILES "/home/zf/scan_viz/src/sbg_driver/config/" REGEX "/\\.git$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zf/scan_viz/build/sbg_driver/sbgECom/cmake_install.cmake")

endif()

