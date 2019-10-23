# ROS-Autoruner

**ROS-Autoruner** is the ROS library used for executing ros nodes or launch scripts sequentially. You can add precedence constraint for each step. It will be very useful when you need to execute a lot of nodes with sequence for your experiment.

---

It is not a complete node but library so you need to write your own source for executing your sequence. So you have to follow conventions. Below screenshot if captured from Autoruner example "Simple Autoruner".

**1. Create your own Autoruner pkg and set CMakeList**
Create Autoruner pkg for executing your sequence. To use library, you need to add some lines in *CMakelist* file.

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#c825ff31c9de44e3b4b7a9952c070411)

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#020d3b1a3edc4ea9b13b400ae11f259c)

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#30fb084c25ae4308a07aed48f8198941)

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#bc7d3fb7da134fae9afc92e834cbd4a7)

**2. Create Autoruner class**

Create your own Autoruner class inherit AutorunerBase in ros_autoruner.h. All of variables and functions without callback is **must** be defined.

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#37f171cd47ff464bb49c03a9ae450731)

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#55d763d69c9e45098ba32772828afd8a)

**3. Create terminate shell script**

You need to create terminate shell script for terminate all steps when you want to quit.

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#e1d6f6615e8640ffae8485414e55efda)

**4. Create step list yaml file**

Set the steps information. You can add step more than 2 ( Limit is maximum number of integer ). You can use rosrun and roslaunch both.

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#d58d0d7c0e7a405486c2842ce7132246)

**5. Create launch file**

Create launch file for execute the autoruner.

[](https://www.notion.so/178e281bcdd84eda84b8de7b58983056#d8dde5a21f80484f8e5c113b2cd36b0d)

**6. Run autoruner**

Execute the launch files then you can see each steps running sequentially if you implement constraint callbacks properly.
