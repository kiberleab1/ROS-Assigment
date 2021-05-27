#!/usr/bin/env python
import rospy
from std_msgs import msg
from std_msgs.msg import Int64
from arm_gazebo.msg import RotationTranslationInput
from arm_gazebo.msg import RotationTranslationOutput
from arm_gazebo.msg import JointValues
class Echo(object):
    def __init__(self):
        self.value=0
        rospy.init_node("echoer2")
        
        rospy.Subscriber("/out_joints",JointValues,self.update_value)
        rospy.spin()
    def update_value(self,msg):
        self.value=msg
        rospy.loginfo(self.value)
    def run(self):
        r=rospy.Rate(10)
        while not rospy.is_shutdown():
            self.pub.publish(self.value+3)
            r.sleep()
if __name__ == '__main__':
    try:
        Echo()
    except rospy.ROSInterruptException: pass