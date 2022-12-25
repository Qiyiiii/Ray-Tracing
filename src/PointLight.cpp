#include "PointLight.h"

void PointLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  //Direction of light depends on position of object relative to light.
  d = (this -> p - q).normalized(); //(light - point) then normalize it
  max_t = (this -> p- q).norm(); // Euclidean distance

  ////////////////////////////////////////////////////////////////////////////
}
