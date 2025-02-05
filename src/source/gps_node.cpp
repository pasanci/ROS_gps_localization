#include "../include/gps_node.h"

GPSLocalization::GPSLocalization(){
}
GPSLocalization::~GPSLocalization(){
}

void GPSLocalization::init(){
    ros::NodeHandle private_nh;
	//private_nh.getParam("robot_namespace", robot_namespace);
	//private_nh.getParam("odometry_topic", odometry_topic);
	//private_nh.getParam("localization_topic", localization_topic);
	private_nh.param<std::string>("robot_namespace", robot_namespace, "/drone1");
	private_nh.param<std::string>("odometry_topic", odometry_topic, "/odometry/filtered");
	private_nh.param<std::string>("localization_topic", localization_topic, "/odometry/filtered");
	ros::Subscriber sub = node_handle.subscribe(robot_namespace+odometry_topic, 100, &GPSLocalization::chatterCallback, this);
	ros::Publisher pub = node_handle.advertise<geometry_msgs::PoseStamped>(robot_namespace+localization_topic, 1000);
}

void GPSLocalization::chatterCallback(const nav_msgs::Odometry &msg){
	//ROS_INFO("I heard: [%s]", msg.child_frame_id);
}

int main(int argc, char **argv){
	std::cout << "init gps_node" << std::endl;
	ros::init(argc, argv, "gps_node");
	GPSLocalization gpsL;
	gpsL.init();
	ros::spin();
	return 0;
}
