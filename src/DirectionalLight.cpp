#include "DirectionalLight.h"
#include <limits>

void DirectionalLight::direction(
  const Eigen::Vector3d & q, Eigen::Vector3d & d, double & max_t) const
{
  ////////////////////////////////////////////////////////////////////////////
  d = ((-1) * (this->d)); //scene go to light
  max_t = std::numeric_limits<double>::infinity(); //its parametric distance from a query point (infinity).
  ////////////////////////////////////////////////////////////////////////////
}

