#!/usr/bin/env python

from __future__ import print_function

import sys
import rospy
from arm_gazebo.srv import *

def add_two_ints_client(x, y):
    rospy.wait_for_service('iks')
    try:
        add_two_ints = rospy.ServiceProxy('iks', ik)
        joint_axis=[0,0,0,0]
        joint_values=[0,0,0,
                      1,1,1,
                      2,2,2,
                      2,3,3]
        target_values=[2,3,3]
        resp1 = add_two_ints(joint_axis,joint_values,target_values)
        return resp1.new_joint_values

    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def usage():
    return "%s [x y]"%sys.argv[0]

if __name__ == "__main__":
    print(add_two_ints_client(1,1))