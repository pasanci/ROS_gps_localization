#ifndef GPS_LOCALIZATION_H
#define GPS_LOCALIZATION_H

#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TwistStamped.h"
#include "nav_msgs/Odometry.h"

class GPSLocalization
{
public:
  GPSLocalization();
  ~GPSLocalization();
  void init();
  void odomCallback(const nav_msgs::Odometry &msg);
  void poseCallback(const geometry_msgs::PoseStamped &msg);
private:
	ros::NodeHandle node_handle;
    std::string robot_namespace;
    std::string odometry_topic;
    std::string localization_topic;
    std::string speed_topic;
    ros::Subscriber odom_sub;
    ros::Subscriber pose_sub;
    ros::Publisher pose_pub;
    ros::Publisher speed_pub;

    geometry_msgs::PoseStamped lastPoseStamped;
};
#endif
