#!/usr/bin/env python

from __future__ import print_function

from arm_gazebo.srv import fk,fkResponse
import tinyik
import rospy
import numpy as np
def handle_add_two_ints(req):
    print("Returning")
    arm=tinyik.Actuator([req.Arm1Axis,[req.Arm1X,req.Arm1Y,req.Arm1Z],
    req.Arm2Axis,[req.Arm2X,req.Arm2Y,req.Arm2Z],req.Arm3Axis,
    [req.Arm3X,req.Arm3Y,req.Arm3Z],req.Arm4Axis,[req.Arm4X,req.Arm4Y,req.Arm4Z]])
    arm.angles=np.deg2rad([req.Arm1Angle,req.Arm2Angle,req.Arm3Angle,req.Arm4Angle])
    return fkResponse(arm.ee[0],arm.ee[1],arm.ee[2])

def add_two_ints_server():
    rospy.init_node('add_two_ints_server')
    s = rospy.Service('fk', fk, handle_add_two_ints)
    print("Ready to add two ints.")
    rospy.spin()


if __name__ == "__main__":
    add_two_ints_server()