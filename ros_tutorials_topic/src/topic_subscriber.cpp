#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"

void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg)
{
	ROS_INFO("receive msg = %d", msg->stamp.sec);
	ROS_INFO("receive msg = %d", msg->stamp.nsec);
	ROS_INFO("receive msg = %d", msg->data);
}

int	main(int argc, char ** argv)
{
	/* code */
	ros::init(argc, argv, "topic_subscriber");

	ros::NodeHandle nh;
	ros::Subscriber ros_tutorials_sub = nh.subscribe("ros_tutorials_msg", 100, msgCallback);
	ros::spin();
	return 0;
}