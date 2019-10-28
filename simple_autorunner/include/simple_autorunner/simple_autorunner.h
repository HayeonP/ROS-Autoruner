
#include <ros/ros.h>
#include <ros_autorunner/ros_autorunner.h>

// Include subscribe message type
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>

#define TOTAL_STEP_NUM 2 // Need to change when total step number is changed

class SimpleAutorunner : public AutorunnerBase{
private:    
    ros::NodeHandle     nh_;
    ROSAutorunner        ros_autorunner_;
private:
    virtual void register_subscribers();
private:
    // CALLBACKS FOR CHECK
    void cmd_vel_cb(const geometry_msgs::Twist& msg);
    void test_cb(const std_msgs::Int32& msg);
public:
    Sub_v               sub_v_;
public:
    SimpleAutorunner() {}
    SimpleAutorunner(ros::NodeHandle nh) : nh_(nh){}
    virtual void Run();
};