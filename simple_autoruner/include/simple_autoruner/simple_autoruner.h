
#include <ros/ros.h>
#include <ros_autoruner/ros_autoruner.h>

// Include subscribe message type
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>

#define TOTAL_STEP_NUM 2 // Need to change when total step number is changed

class SimpleAutoruner : public AutorunerBase{
private:    
    ros::NodeHandle     nh_;
    ROSAutoruner        ros_autoruner_;
private:
    virtual void register_subscribers();
private:
    // CALLBACKS FOR CHECK
    void cmd_vel_cb(const geometry_msgs::Twist& msg);
    void test_cb(const std_msgs::Int32& msg);
public:
    Sub_v               sub_v_;
public:
    SimpleAutoruner() {}
    SimpleAutoruner(ros::NodeHandle nh) : nh_(nh){}
    virtual void Run();
};