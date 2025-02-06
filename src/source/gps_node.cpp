#include "../include/gps_node.h"

GPSLocalization::GPSLocalization(){
}
GPSLocalization::~GPSLocalization(){
}

void GPSLocalization::init(){
    ros::NodeHandle private_nh;
	private_nh.getParam("odometry_topic", odometry_topic);
	private_nh.getParam("localization_topic", localization_topic);
	private_nh.getParam("speed_topic", speed_topic);
	odom_sub = node_handle.subscribe(odometry_topic, 100, &GPSLocalization::odomCallback, this);
	pose_sub = node_handle.subscribe("self_localization/pose2", 100, &GPSLocalization::poseCallback, this);
	pose_pub = node_handle.advertise<geometry_msgs::PoseStamped>(localization_topic, 1000);
	//speed_pub = node_handle.advertise<geometry_msgs::TwistStamped>(speed_topic, 1000);
}

void GPSLocalization::odomCallback(const nav_msgs::Odometry &msg){
	geometry_msgs::PoseStamped newPoseStamped;
	newPoseStamped.header = msg.header;
	newPoseStamped.header.frame_id = "map";
	//newPoseStamped.pose = msg.pose.pose;
	//newPoseStamped.pose = lastPoseStamped.pose;
	newPoseStamped.pose.position = msg.pose.pose.position;
	newPoseStamped.pose.position.z = lastPoseStamped.pose.position.z;
	newPoseStamped.pose.orientation = msg.pose.pose.orientation;
	pose_pub.publish(newPoseStamped);
	geometry_msgs::TwistStamped newSpeedStamped;
	newSpeedStamped.header = msg.header;
	newSpeedStamped.twist = msg.twist.twist;
	//speed_pub.publish(newSpeedStamped);
}

void GPSLocalization::poseCallback(const geometry_msgs::PoseStamped &msg){
	lastPoseStamped.header = msg.header;
	//lastPoseStamped.header.frame_id = "map";
	lastPoseStamped.pose = msg.pose;
}

int main(int argc, char **argv){
	ros::init(argc, argv, "gps_node");
	GPSLocalization gpsL;
	gpsL.init();
	ros::spin();
	return 0;
}
