#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  bool found = false;
  double r_t = 9999999999999;  //recorded smallest t value
  double cur_t;
  Eigen::Vector3d cur_n;

  for (int i = 0; i < objects.size(); i++) {
    if (objects[i]->intersect(ray, min_t, cur_t, cur_n)){
        if (cur_t < r_t && cur_t >= min_t){
          hit_id = i;
          n = cur_n;
          r_t = cur_t;
          t = cur_t;
          found = true;
        }
    }
  }

  return found;
  ////////////////////////////////////////////////////////////////////////////
}

