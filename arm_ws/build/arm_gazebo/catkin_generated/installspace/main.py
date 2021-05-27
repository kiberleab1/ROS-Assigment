#!/usr/bin/env python3
import rospy
from std_msgs import msg
from std_msgs.msg import Int64
import numpy as np
from arm_gazebo.msg import RotationTranslationOutput
from arm_gazebo.msg import RotationTranslationInput
class Echo(object):
    def __init__(self): 
        self.value= RotationTranslationOutput()
        rospy.init_node("rotationCalc")
        
        self.pub=rospy.Publisher("out_value",RotationTranslationOutput,latch=True,queue_size=1)
        rospy.Subscriber("in_value",RotationTranslationInput,self.update_value)
     #   rospy.spin()
    def update_value(self,msg):
        new_value=self.calulate(msg.x,msg.y,msg.z,msg.alpha,msg.beta,msg.gama,msg.d)
        self.value.x=new_value[0]
        self.value.y=new_value[1]
        self.value.z=new_value[2]
        rospy.loginfo(str(self.value))
    def run(self):
        r=rospy.Rate(10)
        while not rospy.is_shutdown():
            self.pub.publish(self.value)
            r.sleep()
    def calulate(self,x,y,z,alpha,beta,gama,d):
        translationMatrix=np.array([[(np.math.cos(alpha)*np.math.cos(beta)),((np.math.cos(alpha)*np.math.sin(beta)*np.math.sin(gama))-(np.math.sin(alpha)*np.math.cos(gama))),
                            ((np.math.cos(alpha)*np.math.sin(beta)*np.math.cos(gama))+(np.math.sin(alpha)*np.math.sin(gama))),d],
                           [(np.math.sin(alpha)*np.math.cos(beta)),((np.math.sin(alpha)*np.math.sin(beta)*np.math.sin(gama))+(np.math.cos(alpha)*np.math.cos(gama))),
                            ((np.math.sin(alpha)*np.math.sin(beta)*np.math.cos(gama))-(np.math.cos(alpha)*np.math.sin(gama))),d],
                           [(-np.math.sin(beta)),((np.math.cos(beta)*np.math.sin(gama))),
                            ((np.math.cos(beta)*np.math.cos(gama))),d],
                           [0,0,0,1]])
        input_vector=np.array([x,
                      y,
                      z,
                      1])
        output_vector=np.matmul(translationMatrix,input_vector,)
        return output_vector
if __name__ == '__main__':
    try:
        Echo().run()
    except rospy.ROSInterruptException: pass