

#include <simple_autorunner/simple_autorunner.h>

void SimpleAutorunner::Run(){
    register_subscribers();             // Register subscribers that shoud check can go next or not
    ros_autorunner_.init(nh_, sub_v_);   // Initialize the ROS-Autorunner
    ros::Rate rate(1);                  // Rate can be changed
    while(ros::ok()){               
        ros_autorunner_.Run();           // Run Autorunner
        ros::spinOnce();
        rate.sleep();
    }    
}

void SimpleAutorunner::register_subscribers(){
    sub_v_.resize(TOTAL_STEP_NUM);          // Resizing the subscriber vectors. Its size must be same with number of steps

    // Set the check function(subscriber)
    sub_v_[STEP(1)] = nh_.subscribe("/cmd_vel", 1, &SimpleAutorunner::cmd_vel_cb, this);
    //sub_v_[STEP(2)] // If you don't need to set subscriber, then pass it
}

void SimpleAutorunner::cmd_vel_cb(const geometry_msgs::Twist& msg){
    if(msg.linear.x >= 1.0){
        ROS_INFO("[simple_autorunner] %lf\n", msg.linear.x);
        ros_autorunner_.step_info_list_[STEP(2)].is_prepared = true;
    }
}




