/* Auto-generated by genmsg_cpp for file /home/mckoval/ros-diamondback/navi_stack/camera_pose/camera_pose_calibration/msg/CameraCalibration.msg */
#ifndef CAMERA_POSE_CALIBRATION_MESSAGE_CAMERACALIBRATION_H
#define CAMERA_POSE_CALIBRATION_MESSAGE_CAMERACALIBRATION_H
#include <string>
#include <vector>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/message.h"
#include "ros/time.h"

#include "geometry_msgs/Pose.h"

namespace camera_pose_calibration
{
template <class ContainerAllocator>
struct CameraCalibration_ : public ros::Message
{
  typedef CameraCalibration_<ContainerAllocator> Type;

  CameraCalibration_()
  : camera_pose()
  , camera_id()
  {
  }

  CameraCalibration_(const ContainerAllocator& _alloc)
  : camera_pose(_alloc)
  , camera_id(_alloc)
  {
  }

  typedef std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other >  _camera_pose_type;
  std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other >  camera_pose;

  typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _camera_id_type;
  std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  camera_id;


  ROS_DEPRECATED uint32_t get_camera_pose_size() const { return (uint32_t)camera_pose.size(); }
  ROS_DEPRECATED void set_camera_pose_size(uint32_t size) { camera_pose.resize((size_t)size); }
  ROS_DEPRECATED void get_camera_pose_vec(std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other > & vec) const { vec = this->camera_pose; }
  ROS_DEPRECATED void set_camera_pose_vec(const std::vector< ::geometry_msgs::Pose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose_<ContainerAllocator> >::other > & vec) { this->camera_pose = vec; }
  ROS_DEPRECATED uint32_t get_camera_id_size() const { return (uint32_t)camera_id.size(); }
  ROS_DEPRECATED void set_camera_id_size(uint32_t size) { camera_id.resize((size_t)size); }
  ROS_DEPRECATED void get_camera_id_vec(std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other > & vec) const { vec = this->camera_id; }
  ROS_DEPRECATED void set_camera_id_vec(const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other > & vec) { this->camera_id = vec; }
private:
  static const char* __s_getDataType_() { return "camera_pose_calibration/CameraCalibration"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "7c56b4c541b0941c246e565a97eb5388"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "geometry_msgs/Pose[] camera_pose\n\
string[] camera_id\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, camera_pose);
    ros::serialization::serialize(stream, camera_id);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, camera_pose);
    ros::serialization::deserialize(stream, camera_id);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(camera_pose);
    size += ros::serialization::serializationLength(camera_id);
    return size;
  }

  typedef boost::shared_ptr< ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::camera_pose_calibration::CameraCalibration_<ContainerAllocator>  const> ConstPtr;
}; // struct CameraCalibration
typedef  ::camera_pose_calibration::CameraCalibration_<std::allocator<void> > CameraCalibration;

typedef boost::shared_ptr< ::camera_pose_calibration::CameraCalibration> CameraCalibrationPtr;
typedef boost::shared_ptr< ::camera_pose_calibration::CameraCalibration const> CameraCalibrationConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace camera_pose_calibration

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator>
struct MD5Sum< ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> > {
  static const char* value() 
  {
    return "7c56b4c541b0941c246e565a97eb5388";
  }

  static const char* value(const  ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x7c56b4c541b0941cULL;
  static const uint64_t static_value2 = 0x246e565a97eb5388ULL;
};

template<class ContainerAllocator>
struct DataType< ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> > {
  static const char* value() 
  {
    return "camera_pose_calibration/CameraCalibration";
  }

  static const char* value(const  ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> > {
  static const char* value() 
  {
    return "geometry_msgs/Pose[] camera_pose\n\
string[] camera_id\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
";
  }

  static const char* value(const  ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.camera_pose);
    stream.next(m.camera_id);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct CameraCalibration_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::camera_pose_calibration::CameraCalibration_<ContainerAllocator> & v) 
  {
    s << indent << "camera_pose[]" << std::endl;
    for (size_t i = 0; i < v.camera_pose.size(); ++i)
    {
      s << indent << "  camera_pose[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "    ", v.camera_pose[i]);
    }
    s << indent << "camera_id[]" << std::endl;
    for (size_t i = 0; i < v.camera_id.size(); ++i)
    {
      s << indent << "  camera_id[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.camera_id[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // CAMERA_POSE_CALIBRATION_MESSAGE_CAMERACALIBRATION_H
