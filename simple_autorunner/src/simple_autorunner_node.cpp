#include <simple_autorunner/simple_autorunner.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "simple_autorunner");
    ros::NodeHandle nh;

    SimpleAutorunner simple_autorunner(nh);
    simple_autorunner.Run();

    return 0;
}