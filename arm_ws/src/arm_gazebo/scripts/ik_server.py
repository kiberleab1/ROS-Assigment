from __future__ import print_function

from arm_gazebo.srv import ik,ikResponse
import tinyik
import rospy
import numpy as np
def handle_add_two_ints(req):
    temp=[]
    k=0
    #print(req.joint_axis)
    
    arm=tinyik.Actuator(["z", [0, 0, 0.15],
    "x", [0, 0, 2.0],
    "x", [0, 0, 1.0],
    "x", [0, 0, .5],
    "z", [0, 0, 0.02],
    "x", [0, 0, 0.02]])
    arm.angles=req.joint_values
   
    arm.ee=req.target_values
    print(req.joint_values)
    print(arm.angles)
    print(req.target_values)

    return ikResponse(arm.angles)

def add_two_ints_server():
    rospy.init_node('add_two_ints_server')
    s = rospy.Service('iks', ik, handle_add_two_ints)
    print("Ready to add two ints.")
    rospy.spin()


if __name__ == "__main__":
    add_two_ints_server()