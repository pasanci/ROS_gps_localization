cmake_minimum_required(VERSION 3.0.2)
project(gps_localization)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

# Directories definition
set(GPS_LOCALIZATION_SOURCE_DIR
  src/source
)

set(GPS_LOCALIZATION_INCLUDE_DIR
  src/include
)

# Files declaration
set(GPS_LOCALIZATION_SOURCE_FILES
  ${GPS_LOCALIZATION_SOURCE_DIR}/gps_node.cpp
)

set(GPS_LOCALIZATION_HEADER_FILES
  ${GPS_LOCALIZATION_INCLUDE_DIR}/gps_node.h
)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS ${GPS_LOCALIZATION_INCLUDE_DIR}
  CATKIN_DEPENDS
  geometry_msgs
  nav_msgs
  roscpp
  std_msgs
)

###########
## Build ##
###########

include_directories(
  ${GPS_LOCALIZATION_INCLUDE_DIR}
  ${GPS_LOCALIZATION_SOURCE_DIR}
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)
add_library(gps_node_lib ${GPS_LOCALIZATION_SOURCE_FILES} ${GPS_LOCALIZATION_HEADER_FILES})
add_dependencies(gps_node_lib ${catkin_EXPORTED_TARGETS})
add_executable(gps_localization_node ${GPS_LOCALIZATION_SOURCE_DIR}/gps_node.cpp)
add_dependencies(gps_localization_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(gps_localization_node gps_node_lib)
target_link_libraries(gps_localization_node ${catkin_LIBRARIES})