#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  double A = ray.direction.dot(ray.direction); //(d dot d)^2
  double B = 2 * (ray.direction).dot(ray.origin - center); //2d dot (e-c)
  double C = (ray.origin - center).dot(ray.origin - center) - radius * radius; // (e-c) dot (e-c) -r^2

  double disc = B*B - 4*A*C; //discriminant 

  if (disc < 0){ // no result
    return false;
  }
  else{
    double t1 = (-B + sqrt(disc)) / (2 * A);
    double t2 = (-B - sqrt(disc)) / (2 * A);    //t1 >= t2, A>0
    if (t2 >= min_t){
      t = t2;
      n = (ray.origin + t * ray.direction - center).normalized();
      return true;
    }
    else if (t1 >= min_t){
      t = t2;
      n = (ray.origin + t * ray.direction - center).normalized();
      return true;
  }

  return false;}
  ////////////////////////////////////////////////////////////////////////////
}

