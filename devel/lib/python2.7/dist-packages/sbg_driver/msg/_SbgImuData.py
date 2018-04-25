# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from sbg_driver/SbgImuData.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import sbg_driver.msg
import std_msgs.msg

class SbgImuData(genpy.Message):
  _md5sum = "59cc541d794c367e71030fa700720826"
  _type = "sbg_driver/SbgImuData"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """# SBG Ellipse Messages
Header header

# Time since sensor is powered up μs 
uint32 time_stamp

# IMU Status
SbgImuStatus imu_status

# Filtered Accelerometer – X, Y, Z axis m/s2 
geometry_msgs/Vector3 accel

# Filtered Gyroscope – X, Y, Z axis rad/s 
geometry_msgs/Vector3 gyro

# Internal Temperature °C 
float32 temp

# Sculling output – X, Y, Z axis m/s2 
geometry_msgs/Vector3 delta_vel

# Coning output – X, Y, Z axis rad/s 
geometry_msgs/Vector3 delta_angle

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

================================================================================
MSG: sbg_driver/SbgImuStatus
# SBG Ellipse Messages
# Submessage SbgImuData

# True if the communication with the IMU is ok.
bool imu_com

# True if internal IMU passes Built In Test (Calibration, CPU)
bool imu_status

# True if accelerometer X passes Built In Test
bool imu_accel_x

# True if accelerometer Y passes Built In Test
bool imu_accel_y

# True if accelerometer Z passes Built In Test
bool imu_accel_z

# True if gyroscope X passes Built In Test
bool imu_gyro_x

# True if gyroscope Y passes Built In Test
bool imu_gyro_y

# True if gyroscope Z passes Built In Test
bool imu_gyro_z

# True if accelerometers are within operating range
bool imu_accels_in_range

# True if gyroscopes are within operating range
bool imu_gyros_in_range

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z"""
  __slots__ = ['header','time_stamp','imu_status','accel','gyro','temp','delta_vel','delta_angle']
  _slot_types = ['std_msgs/Header','uint32','sbg_driver/SbgImuStatus','geometry_msgs/Vector3','geometry_msgs/Vector3','float32','geometry_msgs/Vector3','geometry_msgs/Vector3']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,time_stamp,imu_status,accel,gyro,temp,delta_vel,delta_angle

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SbgImuData, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.time_stamp is None:
        self.time_stamp = 0
      if self.imu_status is None:
        self.imu_status = sbg_driver.msg.SbgImuStatus()
      if self.accel is None:
        self.accel = geometry_msgs.msg.Vector3()
      if self.gyro is None:
        self.gyro = geometry_msgs.msg.Vector3()
      if self.temp is None:
        self.temp = 0.
      if self.delta_vel is None:
        self.delta_vel = geometry_msgs.msg.Vector3()
      if self.delta_angle is None:
        self.delta_angle = geometry_msgs.msg.Vector3()
    else:
      self.header = std_msgs.msg.Header()
      self.time_stamp = 0
      self.imu_status = sbg_driver.msg.SbgImuStatus()
      self.accel = geometry_msgs.msg.Vector3()
      self.gyro = geometry_msgs.msg.Vector3()
      self.temp = 0.
      self.delta_vel = geometry_msgs.msg.Vector3()
      self.delta_angle = geometry_msgs.msg.Vector3()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_I10B6df6d().pack(_x.time_stamp, _x.imu_status.imu_com, _x.imu_status.imu_status, _x.imu_status.imu_accel_x, _x.imu_status.imu_accel_y, _x.imu_status.imu_accel_z, _x.imu_status.imu_gyro_x, _x.imu_status.imu_gyro_y, _x.imu_status.imu_gyro_z, _x.imu_status.imu_accels_in_range, _x.imu_status.imu_gyros_in_range, _x.accel.x, _x.accel.y, _x.accel.z, _x.gyro.x, _x.gyro.y, _x.gyro.z, _x.temp, _x.delta_vel.x, _x.delta_vel.y, _x.delta_vel.z, _x.delta_angle.x, _x.delta_angle.y, _x.delta_angle.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.imu_status is None:
        self.imu_status = sbg_driver.msg.SbgImuStatus()
      if self.accel is None:
        self.accel = geometry_msgs.msg.Vector3()
      if self.gyro is None:
        self.gyro = geometry_msgs.msg.Vector3()
      if self.delta_vel is None:
        self.delta_vel = geometry_msgs.msg.Vector3()
      if self.delta_angle is None:
        self.delta_angle = geometry_msgs.msg.Vector3()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 114
      (_x.time_stamp, _x.imu_status.imu_com, _x.imu_status.imu_status, _x.imu_status.imu_accel_x, _x.imu_status.imu_accel_y, _x.imu_status.imu_accel_z, _x.imu_status.imu_gyro_x, _x.imu_status.imu_gyro_y, _x.imu_status.imu_gyro_z, _x.imu_status.imu_accels_in_range, _x.imu_status.imu_gyros_in_range, _x.accel.x, _x.accel.y, _x.accel.z, _x.gyro.x, _x.gyro.y, _x.gyro.z, _x.temp, _x.delta_vel.x, _x.delta_vel.y, _x.delta_vel.z, _x.delta_angle.x, _x.delta_angle.y, _x.delta_angle.z,) = _get_struct_I10B6df6d().unpack(str[start:end])
      self.imu_status.imu_com = bool(self.imu_status.imu_com)
      self.imu_status.imu_status = bool(self.imu_status.imu_status)
      self.imu_status.imu_accel_x = bool(self.imu_status.imu_accel_x)
      self.imu_status.imu_accel_y = bool(self.imu_status.imu_accel_y)
      self.imu_status.imu_accel_z = bool(self.imu_status.imu_accel_z)
      self.imu_status.imu_gyro_x = bool(self.imu_status.imu_gyro_x)
      self.imu_status.imu_gyro_y = bool(self.imu_status.imu_gyro_y)
      self.imu_status.imu_gyro_z = bool(self.imu_status.imu_gyro_z)
      self.imu_status.imu_accels_in_range = bool(self.imu_status.imu_accels_in_range)
      self.imu_status.imu_gyros_in_range = bool(self.imu_status.imu_gyros_in_range)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_I10B6df6d().pack(_x.time_stamp, _x.imu_status.imu_com, _x.imu_status.imu_status, _x.imu_status.imu_accel_x, _x.imu_status.imu_accel_y, _x.imu_status.imu_accel_z, _x.imu_status.imu_gyro_x, _x.imu_status.imu_gyro_y, _x.imu_status.imu_gyro_z, _x.imu_status.imu_accels_in_range, _x.imu_status.imu_gyros_in_range, _x.accel.x, _x.accel.y, _x.accel.z, _x.gyro.x, _x.gyro.y, _x.gyro.z, _x.temp, _x.delta_vel.x, _x.delta_vel.y, _x.delta_vel.z, _x.delta_angle.x, _x.delta_angle.y, _x.delta_angle.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.imu_status is None:
        self.imu_status = sbg_driver.msg.SbgImuStatus()
      if self.accel is None:
        self.accel = geometry_msgs.msg.Vector3()
      if self.gyro is None:
        self.gyro = geometry_msgs.msg.Vector3()
      if self.delta_vel is None:
        self.delta_vel = geometry_msgs.msg.Vector3()
      if self.delta_angle is None:
        self.delta_angle = geometry_msgs.msg.Vector3()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 114
      (_x.time_stamp, _x.imu_status.imu_com, _x.imu_status.imu_status, _x.imu_status.imu_accel_x, _x.imu_status.imu_accel_y, _x.imu_status.imu_accel_z, _x.imu_status.imu_gyro_x, _x.imu_status.imu_gyro_y, _x.imu_status.imu_gyro_z, _x.imu_status.imu_accels_in_range, _x.imu_status.imu_gyros_in_range, _x.accel.x, _x.accel.y, _x.accel.z, _x.gyro.x, _x.gyro.y, _x.gyro.z, _x.temp, _x.delta_vel.x, _x.delta_vel.y, _x.delta_vel.z, _x.delta_angle.x, _x.delta_angle.y, _x.delta_angle.z,) = _get_struct_I10B6df6d().unpack(str[start:end])
      self.imu_status.imu_com = bool(self.imu_status.imu_com)
      self.imu_status.imu_status = bool(self.imu_status.imu_status)
      self.imu_status.imu_accel_x = bool(self.imu_status.imu_accel_x)
      self.imu_status.imu_accel_y = bool(self.imu_status.imu_accel_y)
      self.imu_status.imu_accel_z = bool(self.imu_status.imu_accel_z)
      self.imu_status.imu_gyro_x = bool(self.imu_status.imu_gyro_x)
      self.imu_status.imu_gyro_y = bool(self.imu_status.imu_gyro_y)
      self.imu_status.imu_gyro_z = bool(self.imu_status.imu_gyro_z)
      self.imu_status.imu_accels_in_range = bool(self.imu_status.imu_accels_in_range)
      self.imu_status.imu_gyros_in_range = bool(self.imu_status.imu_gyros_in_range)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_I10B6df6d = None
def _get_struct_I10B6df6d():
    global _struct_I10B6df6d
    if _struct_I10B6df6d is None:
        _struct_I10B6df6d = struct.Struct("<I10B6df6d")
    return _struct_I10B6df6d
