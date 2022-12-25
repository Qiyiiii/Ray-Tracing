#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  rgb = Eigen::Vector3d(0,0,0);

  int hit;
  double t;
  Eigen::Vector3d n;
  if (first_hit(ray, min_t, objects, hit, t, n) && num_recursive_calls < 100) { //if ray gets a hit  
  
    rgb += blinn_phong_shading(ray, hit, t, n, objects, lights); //get deffuse color
      Ray nr;
      nr.direction = reflect(ray.direction, n);
      nr.origin = ray.origin + t * ray.direction;
      Eigen::Vector3d nrgb;
      if(raycolor(nr, 0.00000001, objects, lights, num_recursive_calls + 1, nrgb)){
        rgb += (objects[hit]->material->km.array() * nrgb.array()).matrix(); //mirror surface

      }
      return true;
      
      }
  
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
