#ifndef GPS_LOCALIZATION_H
#define GPS_LOCALIZATION_H

#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "nav_msgs/Odometry.h"

class GPSLocalization
{
public:
  GPSLocalization();
  ~GPSLocalization();
  void init();
  void chatterCallback(const nav_msgs::Odometry &msg);
private:
	ros::NodeHandle node_handle;
    std::string robot_namespace;
    std::string odometry_topic;
    std::string localization_topic;
    ros::Subscriber sub;
    ros::Publisher pub;
};
#endif
