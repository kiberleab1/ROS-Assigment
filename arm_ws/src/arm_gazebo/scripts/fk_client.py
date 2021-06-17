#!/usr/bin/env python

from __future__ import print_function

import sys
import rospy
from arm_gazebo.srv import *

def add_two_ints_client(x, y):
    rospy.wait_for_service('fk')
    try:
        add_two_ints = rospy.ServiceProxy('fk', fk)
        resp1 = add_two_ints('x',1., 0., 0.,30,'z',1., 0., 0.,30,'x',1., 0., 0.,30,'x',1., 0., 0.,30)
        return resp1.endX,resp1.endY,resp1.endZ
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def usage():
    return "%s [x y]"%sys.argv[0]


if __name__ == "__main__":
    print("%s + %s = %s"%(add_two_ints_client(1,1)))