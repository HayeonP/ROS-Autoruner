#include <simple_autoruner/simple_autoruner.h>

int main(int argc, char* argv[]){
    ros::init(argc, argv, "simple_autoruner");
    ros::NodeHandle nh;

    SimpleAutoruner simple_autoruner(nh);
    simple_autoruner.Run();

    return 0;
}