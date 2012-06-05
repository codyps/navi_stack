#!/usr/bin/env python
import roslib; roslib.load_manifest('navi_calibration')
import rospy, math, tf
import numpy as np
from sensor_msgs.msg import Imu

def callback(msg):
    qt_raw = np.array([ msg.orientation.x, msg.orientation.y,
                        msg.orientation.z, msg.orientation.w ])
    roll, pitch, yaw = tf.transformations.euler_from_quaternion(qt_raw)
    roll  = roll + math.pi
    pitch = -pitch
    print roll, pitch
    qt = tf.transformations.quaternion_from_euler(roll, pitch, 0.0)
    pub_tf.sendTransform((0, 0, 0), qt, msg.header.stamp,
                         base_frame_id, rotated_frame_id);

def main():
    global base_frame_id, rotated_frame_id, pub_tf
    rospy.init_node('fix_rotation')
    
    base_frame_id = rospy.get_param('~base_frame', '/base_footprint')
    rotated_frame_id = rospy.get_param('~rotated_frame', '/base_footprint_rotated')

    sub = rospy.Subscriber('compass', Imu, callback)
    pub_tf = tf.TransformBroadcaster()
    rospy.spin()

if __name__ == '__main__':
    main()
