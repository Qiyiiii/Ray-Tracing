#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Dense>
#include <iostream>
bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Vector3d t1, t2;
  t1 = std::get<0>(corners) - std::get<1>(corners);
  t2 = std::get<2>(corners) - std::get<1>(corners);
  n = -(t1.cross(t2)).normalized();

  Eigen::Matrix3d mat;
  mat << t1, t2, -ray.direction;
  mat.transpose();
  Eigen::Vector3d ABt = mat.inverse() * (ray.origin - std::get<1>(corners)); //A,B,t = <t1, t2, -d).inverse * (e-offset)

	double alpha = ABt[0];
	double beta = ABt[1];
	//   std::cout << alpha <<" ";
  t = (ABt[2]);
  if (alpha >= 0 && beta >= 0 && alpha+beta <= 1 && t >= min_t){
	  return true;
  }
  else{
	  return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}


