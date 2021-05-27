;; Auto-generated. Do not edit!


(when (boundp 'arm_gazebo::JointValues)
  (if (not (find-package "ARM_GAZEBO"))
    (make-package "ARM_GAZEBO"))
  (shadow 'JointValues (find-package "ARM_GAZEBO")))
(unless (find-package "ARM_GAZEBO::JOINTVALUES")
  (make-package "ARM_GAZEBO::JOINTVALUES"))

(in-package "ROS")
;;//! \htmlinclude JointValues.msg.html


(defclass arm_gazebo::JointValues
  :super ros::object
  :slots (_joint1 _joint2 _joint3 _joint4 ))

(defmethod arm_gazebo::JointValues
  (:init
   (&key
    ((:joint1 __joint1) 0.0)
    ((:joint2 __joint2) 0.0)
    ((:joint3 __joint3) 0.0)
    ((:joint4 __joint4) 0.0)
    )
   (send-super :init)
   (setq _joint1 (float __joint1))
   (setq _joint2 (float __joint2))
   (setq _joint3 (float __joint3))
   (setq _joint4 (float __joint4))
   self)
  (:joint1
   (&optional __joint1)
   (if __joint1 (setq _joint1 __joint1)) _joint1)
  (:joint2
   (&optional __joint2)
   (if __joint2 (setq _joint2 __joint2)) _joint2)
  (:joint3
   (&optional __joint3)
   (if __joint3 (setq _joint3 __joint3)) _joint3)
  (:joint4
   (&optional __joint4)
   (if __joint4 (setq _joint4 __joint4)) _joint4)
  (:serialization-length
   ()
   (+
    ;; float64 _joint1
    8
    ;; float64 _joint2
    8
    ;; float64 _joint3
    8
    ;; float64 _joint4
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _joint1
       (sys::poke _joint1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _joint2
       (sys::poke _joint2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _joint3
       (sys::poke _joint3 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _joint4
       (sys::poke _joint4 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _joint1
     (setq _joint1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _joint2
     (setq _joint2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _joint3
     (setq _joint3 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _joint4
     (setq _joint4 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get arm_gazebo::JointValues :md5sum-) "fb6e7c37be4d0e82de5529136096fb87")
(setf (get arm_gazebo::JointValues :datatype-) "arm_gazebo/JointValues")
(setf (get arm_gazebo::JointValues :definition-)
      "float64 joint1
float64 joint2
float64 joint3
float64 joint4
")



(provide :arm_gazebo/JointValues "fb6e7c37be4d0e82de5529136096fb87")


