#!/usr/bin/env python3
import rospy
from std_msgs.msg import Int64
from arm_gazebo.msg import RotationTranslationInput
def talker():
    pub = rospy.Publisher('in_value',RotationTranslationInput,queue_size=100)
    rospy.init_node('in_value', anonymous=True)
    r = rospy.Rate(10) #10hz
    msg = RotationTranslationInput()
    msg.x=1.0
    msg.y=1.0
    msg.z=1.0
    msg.alpha=0.0
    msg.beta=0.0
    msg.gama=0.0
    msg.d=2

    while not rospy.is_shutdown():
        #rospy.loginfo(msg)
        pub.publish(msg)
        r.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass