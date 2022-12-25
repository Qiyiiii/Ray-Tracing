#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  ray.origin = camera.e;
  //   i  pixel row index   -> y
  //   j  pixel column index -> x
  double x = -(camera.width * 0.5) + (camera.width * (j + 0.5) / width);
  double y = (camera.height * 0.5) - (camera.height * (i + 0.5) / height);

  ray.direction = (x * camera.u + y * camera.v - camera.d * camera.w).normalized();
  ////////////////////////////////////////////////////////////////////////////
}

