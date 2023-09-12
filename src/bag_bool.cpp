#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Float32.h"
#include "bag_bool.h"


class SubscribeAndPublish{

	public: SubscribeAndPublish()
	{
		pub_bool = nh_bool.advertise<std_msgs::Bool>("/robot_on_target", 5);
		
		sub_bool = nh_bool.subscribe("/sonar_dist", 5, &SubscribeAndPublish:: posCallback, this);
	}
	
	void posCallback(const std_msgs::Float32::ConstPtr& msg)

	{

		float threshold;
		int consec_count_filter;
		nh_bool.getParam("/bag_bool/threshold",threshold);
		nh_bool.getParam("/bag_bool/consec_count",consec_count_filter);
		
		std_msgs::Bool res;
		dist = msg->data;
		ROS_INFO("dist:%f", dist);
		if(dist > threshold){
			res.data = false;
			consecutive_count = 0;
			
		}else if(consecutive_count < consec_count_filter){
			res.data = false;
			consecutive_count++;
		}else{
			res.data = true;
		}
		pub_bool.publish(res);
	} 


	private:
		ros::NodeHandle nh_bool;
		ros::Publisher pub_bool;
		ros::Subscriber sub_bool;

};

int main(int argc, char** argv)
{

	consecutive_count = 0;
	
	ros::init(argc, argv, "bag_bool_pub");
        ros::NodeHandle _nh;
	
	SubscribeAndPublish bag_bool;
	


	// ros::spin();
	
	// return 0;
	

	
	ros::Rate loop_rate(20);
	
	while(ros::ok())
	{
        loop_rate.sleep();
        ros::spinOnce();
	}

    printf("Terminate: bag_bool_pub\n");
}
