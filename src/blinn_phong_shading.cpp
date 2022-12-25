#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Vector3d rgb = Eigen::Vector3d(0, 0, 0);
  // for (int i =0; i<4; i++){
  rgb += (0.1*(objects[hit_id]->material->ka.array())).matrix();  //ambient color  * 0.1
  
  double mt;
  for (int i = 0; i < lights.size(); i++) { //do all light contributions
 
    Ray r;  //throw ray at light
    Eigen::Vector3d p = ray.origin + t * ray.direction; //ray origin
    Eigen::Vector3d rd; //ray direction
    lights[i]->direction(p, rd, mt);
    r.origin = p;
    r.direction = rd;
    int nhit;
    double nt;
    Eigen::Vector3d nn;
    if (!first_hit(r, 0.00000001 , objects, nhit, nt, nn) || nt > mt){ //check if showdow ray not hits and if not in shadow
    //add blinn shadow
      rgb += ((objects[hit_id] -> material -> kd.array() ) * lights[i]->I.array()* std::max(0.0, n.dot(r.direction))).matrix() ; //Lambertian shading
        
      rgb += ((objects[hit_id] -> material -> ks.array() )* lights[i]->I.array()* std::pow(std::max(0.0, n.dot((-(ray.direction) + rd).normalized())), (objects[hit_id]->material->phong_exponent))).matrix()  ; //specular
  }
  }
  
  return rgb;
  ////////////////////////////////////////////////////////////////////////////
}
