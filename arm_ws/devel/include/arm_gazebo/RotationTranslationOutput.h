// Generated by gencpp from file arm_gazebo/RotationTranslationOutput.msg
// DO NOT EDIT!


#ifndef ARM_GAZEBO_MESSAGE_ROTATIONTRANSLATIONOUTPUT_H
#define ARM_GAZEBO_MESSAGE_ROTATIONTRANSLATIONOUTPUT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace arm_gazebo
{
template <class ContainerAllocator>
struct RotationTranslationOutput_
{
  typedef RotationTranslationOutput_<ContainerAllocator> Type;

  RotationTranslationOutput_()
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
    }
  RotationTranslationOutput_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> const> ConstPtr;

}; // struct RotationTranslationOutput_

typedef ::arm_gazebo::RotationTranslationOutput_<std::allocator<void> > RotationTranslationOutput;

typedef boost::shared_ptr< ::arm_gazebo::RotationTranslationOutput > RotationTranslationOutputPtr;
typedef boost::shared_ptr< ::arm_gazebo::RotationTranslationOutput const> RotationTranslationOutputConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator1> & lhs, const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator1> & lhs, const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace arm_gazebo

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4a842b65f413084dc2b10fb484ea7f17";
  }

  static const char* value(const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4a842b65f413084dULL;
  static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
};

template<class ContainerAllocator>
struct DataType< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "arm_gazebo/RotationTranslationOutput";
  }

  static const char* value(const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RotationTranslationOutput_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::arm_gazebo::RotationTranslationOutput_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARM_GAZEBO_MESSAGE_ROTATIONTRANSLATIONOUTPUT_H