;; Auto-generated. Do not edit!


(when (boundp 'arm_gazebo::RotationTranslationInput)
  (if (not (find-package "ARM_GAZEBO"))
    (make-package "ARM_GAZEBO"))
  (shadow 'RotationTranslationInput (find-package "ARM_GAZEBO")))
(unless (find-package "ARM_GAZEBO::ROTATIONTRANSLATIONINPUT")
  (make-package "ARM_GAZEBO::ROTATIONTRANSLATIONINPUT"))

(in-package "ROS")
;;//! \htmlinclude RotationTranslationInput.msg.html


(defclass arm_gazebo::RotationTranslationInput
  :super ros::object
  :slots (_x _y _z _alpha _beta _gama _d ))

(defmethod arm_gazebo::RotationTranslationInput
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:alpha __alpha) 0.0)
    ((:beta __beta) 0.0)
    ((:gama __gama) 0.0)
    ((:d __d) 0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _alpha (float __alpha))
   (setq _beta (float __beta))
   (setq _gama (float __gama))
   (setq _d (round __d))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:alpha
   (&optional __alpha)
   (if __alpha (setq _alpha __alpha)) _alpha)
  (:beta
   (&optional __beta)
   (if __beta (setq _beta __beta)) _beta)
  (:gama
   (&optional __gama)
   (if __gama (setq _gama __gama)) _gama)
  (:d
   (&optional __d)
   (if __d (setq _d __d)) _d)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ;; float64 _alpha
    8
    ;; float64 _beta
    8
    ;; float64 _gama
    8
    ;; int64 _d
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _alpha
       (sys::poke _alpha (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _beta
       (sys::poke _beta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _gama
       (sys::poke _gama (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _d
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _d (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _d) (= (length (_d . bv)) 2)) ;; bignum
              (write-long (ash (elt (_d . bv) 0) 0) s)
              (write-long (ash (elt (_d . bv) 1) -1) s))
             ((and (class _d) (= (length (_d . bv)) 1)) ;; big1
              (write-long (elt (_d . bv) 0) s)
              (write-long (if (>= _d 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _d s)(write-long (if (>= _d 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _alpha
     (setq _alpha (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _beta
     (setq _beta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _gama
     (setq _gama (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _d
#+(or :alpha :irix6 :x86_64)
      (setf _d (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _d (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get arm_gazebo::RotationTranslationInput :md5sum-) "bbe30b78a86e6a76f83d6f916d1be6e8")
(setf (get arm_gazebo::RotationTranslationInput :datatype-) "arm_gazebo/RotationTranslationInput")
(setf (get arm_gazebo::RotationTranslationInput :definition-)
      "float64 x
float64 y
float64 z

float64 alpha
float64 beta
float64 gama

int64 d
")



(provide :arm_gazebo/RotationTranslationInput "bbe30b78a86e6a76f83d6f916d1be6e8")


