#!/usr/bin/env python
import rospy
from arm_gazebo.msg import GripCommand
from arm_gazebo.msg import RotationTranslationInput
def talker():
    pub = rospy.Publisher('command_chatter',GripCommand,queue_size=100)
    rospy.init_node('command_chatter', anonymous=True)
    r = rospy.Rate(1000) #10hz
    msg=GripCommand()
    

    while not rospy.is_shutdown():
        #rospy.loginfo(msg)
        command=input("command: ")
        msg.grip_command=command
        pub.publish(msg)
        r.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass