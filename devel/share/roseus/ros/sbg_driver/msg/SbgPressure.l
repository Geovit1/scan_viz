;; Auto-generated. Do not edit!


(when (boundp 'sbg_driver::SbgPressure)
  (if (not (find-package "SBG_DRIVER"))
    (make-package "SBG_DRIVER"))
  (shadow 'SbgPressure (find-package "SBG_DRIVER")))
(unless (find-package "SBG_DRIVER::SBGPRESSURE")
  (make-package "SBG_DRIVER::SBGPRESSURE"))

(in-package "ROS")
;;//! \htmlinclude SbgPressure.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass sbg_driver::SbgPressure
  :super ros::object
  :slots (_header _time_stamp _valid_pressure _valid_altitude _pressure _altitude ))

(defmethod sbg_driver::SbgPressure
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:time_stamp __time_stamp) 0)
    ((:valid_pressure __valid_pressure) nil)
    ((:valid_altitude __valid_altitude) nil)
    ((:pressure __pressure) 0.0)
    ((:altitude __altitude) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _time_stamp (round __time_stamp))
   (setq _valid_pressure __valid_pressure)
   (setq _valid_altitude __valid_altitude)
   (setq _pressure (float __pressure))
   (setq _altitude (float __altitude))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:time_stamp
   (&optional __time_stamp)
   (if __time_stamp (setq _time_stamp __time_stamp)) _time_stamp)
  (:valid_pressure
   (&optional __valid_pressure)
   (if __valid_pressure (setq _valid_pressure __valid_pressure)) _valid_pressure)
  (:valid_altitude
   (&optional __valid_altitude)
   (if __valid_altitude (setq _valid_altitude __valid_altitude)) _valid_altitude)
  (:pressure
   (&optional __pressure)
   (if __pressure (setq _pressure __pressure)) _pressure)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _time_stamp
    4
    ;; bool _valid_pressure
    1
    ;; bool _valid_altitude
    1
    ;; float32 _pressure
    4
    ;; float32 _altitude
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _time_stamp
       (write-long _time_stamp s)
     ;; bool _valid_pressure
       (if _valid_pressure (write-byte -1 s) (write-byte 0 s))
     ;; bool _valid_altitude
       (if _valid_altitude (write-byte -1 s) (write-byte 0 s))
     ;; float32 _pressure
       (sys::poke _pressure (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _time_stamp
     (setq _time_stamp (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _valid_pressure
     (setq _valid_pressure (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _valid_altitude
     (setq _valid_altitude (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _pressure
     (setq _pressure (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _altitude
     (setq _altitude (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get sbg_driver::SbgPressure :md5sum-) "89c42b030bba29be5014a72c91d4821d")
(setf (get sbg_driver::SbgPressure :datatype-) "sbg_driver/SbgPressure")
(setf (get sbg_driver::SbgPressure :definition-)
      "# SBG Ellipse Messages
Header header

# Time since sensor is powered up μs 
uint32 time_stamp

# Pressure status (True if the altimeter equipment was correctly initialized)
bool valid_pressure

# Altitude (True if the altitude output is valid)
bool valid_altitude

# Pressure measured by the sensor (Pa)
float32 pressure

# Altitude computed from altitude (m)
float32 altitude
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :sbg_driver/SbgPressure "89c42b030bba29be5014a72c91d4821d")


