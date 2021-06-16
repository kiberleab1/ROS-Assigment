#!/bin/bash
rostopic pub --once /coming_joints arm_gazebo/JointValues "x: 2.3 y: 0.3 z: 0.0" 
rostopic pub --once /command_chatter arm_gazebo/GripCommand catch 
rostopic pub --once /coming_joints arm_gazebo/JointValues "x: 1.3 y: 0.3 z: 2.0" 
rostopic pub --once /command_chatter arm_gazebo/GripCommand release 
