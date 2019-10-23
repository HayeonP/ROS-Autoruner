

#include <simple_autoruner/simple_autoruner.h>

void SimpleAutoruner::Run(){
    register_subscribers();             // Register subscribers that shoud check can go next or not
    ros_autoruner_.init(nh_, sub_v_);   // Initialize the ROS-Autoruner
    ros::Rate rate(1);                  // Rate can be changed
    while(ros::ok()){               
        ros_autoruner_.Run();           // Run Autoruner
        ros::spinOnce();
        rate.sleep();
    }    
}

void SimpleAutoruner::register_subscribers(){
    sub_v_.resize(TOTAL_STEP_NUM);          // Resizing the subscriber vectors. Its size must be same with number of steps

    // Set the check function(subscriber)
    sub_v_[STEP(1)] = nh_.subscribe("/cmd_vel", 1, &SimpleAutoruner::cmd_vel_cb, this);
    //sub_v_[STEP(2)] // If you don't need to set subscriber, then pass it
}

void SimpleAutoruner::cmd_vel_cb(const geometry_msgs::Twist& msg){
    if(msg.linear.x >= 1.0){
        ROS_INFO("[simple_autoruner] %lf\n", msg.linear.x);
        ros_autoruner_.step_info_list_[STEP(2)].is_prepared = true;
    }
}




