#!/usr/bin/env python
import rospy
from std_msgs.msg import Int64
from arm_gazebo.msg import RotationTranslationInput
from arm_gazebo.msg import JointValues

def talker():
    pub = rospy.Publisher('/coming_joints',JointValues,queue_size=100)
    rospy.init_node('tester1', anonymous=True)
    r = rospy.Rate(10) #10hz
    msg = JointValues()
    msg.joint1=1.0
    msg.joint4=1.0
    msg.joint2=1.0
    msg.joint3=0.0
   

    while not rospy.is_shutdown():
        #rospy.loginfo(msg)
        pub.publish(msg)
        r.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass