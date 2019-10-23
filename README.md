# ROS-Autoruner

**ROS-Autoruner** is the ROS library used for executing ros nodes or launch scripts sequentially. You can add precedence constraint for each step. It will be very useful when you need to execute a lot of nodes with sequence for your experiment.

---

It is not a complete node but library so you need to write your own source for executing your sequence. So you have to follow conventions. Below screenshot if captured from Autoruner example "Simple Autoruner".

**1. Create your own Autoruner pkg and set CMakeList**
Create Autoruner pkg for executing your sequence. To use library, you need to add some lines in *CMakelist* file.

![Optional Text](../master/ros-autoruner-img/1_lib_location.png)

![Optional Text](../master/ros-autoruner-img/2_compile_option.png)

![Optional Text](../master/ros-autoruner-img/3_include_directory.png)

![Optional Text](../master/ros-autoruner-img/4_add_library.png)

**2. Create Autoruner class**

Create your own Autoruner class inherit AutorunerBase in ros_autoruner.h. All of variables and functions without callback is **must** be defined.

![Optional Text](../master/ros-autoruner-img/5_SimpleAutorunerClass.png)

![Optional Text](../master/ros-autoruner-img/6_simple_autoruner_class_implementation.png)

**3. Create terminate shell script**

You need to create terminate shell script for terminate all steps when you want to quit.

![Optional Text](../master/ros-autoruner-img/7_terminate_node_list.png)

**4. Create step list yaml file**

Set the steps information. You can add step more than 2 ( Limit is maximum number of integer ). You can use rosrun and roslaunch both.

![Optional Text](../master/ros-autoruner-img/8_terminate_shell_script.png)

**5. Create launch file**

Create launch file for execute the autoruner.

![Optional Text](../master/ros-autoruner-img/9_launch_file.png)

**6. Run autoruner**

Execute the launch files then you can see each steps running sequentially if you implement constraint callbacks properly.
