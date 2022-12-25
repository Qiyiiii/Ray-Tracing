#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  n = normal.normalized();
   if (n.dot(ray.direction) == 0) { // ray parallel to plane
    return false;
  }
  else{
    t = -n.dot(ray.origin - point) / (n.dot(ray.direction));
  }
  return t >= min_t;
  ////////////////////////////////////////////////////////////////////////////
}

