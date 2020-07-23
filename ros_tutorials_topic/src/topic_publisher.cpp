#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"

int main(int argc, char ** argv)
{
	ros::init(argc, argv, "topic_publisher");
	ros::NodeHandle nh;

	ros::Publisher ros_tutorials_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorials_msg", 100);

	ros::Rate loop_rate = 1; // loop_rate(1);

	ros_tutorials_topic::MsgTutorial msg;

	int count = 0;
	while(ros::ok())
	{
		msg.stamp = ros::Time::now();
		msg.data = count;

		ROS_INFO("send msg stamp.sec = %d", msg.stamp.sec);
		ROS_INFO("send msg stamp.nsec = %d", msg.stamp.nsec);
		ROS_INFO("send msg data = %d", msg.data);

		ros_tutorials_pub.publish(msg);

		loop_rate.sleep();

		++count;
	}
	// while(ros::ok())
	// {
	// 	msg.stamp = ros::Time::now();
	// 	msg.data = count;

	// 	ROS_INFO("send msg stamp.sec = %d", msg.stamp.sec);
	// 	ROS_INFO("send msg stamp.nsec = %d", msg.stamp.nsec);
	// 	ROS_INFO("send msg data = %d", msg.data);

	// 	ros_tutorials_pub.publish(msg);

	// 	ros::Duration(1).sleep();

	// 	++count;
	// }
	return 0;
}