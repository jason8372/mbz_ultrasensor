cmake_minimum_required(VERSION 3.0.2)
project(sensor_direct)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roslib
  roscpp
  rospy
  std_msgs
)

catkin_package(
 INCLUDE_DIRS include
#  LIBRARIES tk_uav_control
#  CATKIN_DEPENDS geometry_msgs mav_msgs mavros mavros_extras mavros_msgs nav_msgs roscpp tf tk_uav_dob timing_ros
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


add_executable(bag_bool src/bag_bool.cpp)
add_dependencies(bag_bool ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(bag_bool ${catkin_LIBRARIES})
