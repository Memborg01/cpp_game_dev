#include "camera.hpp"
#include "enemy_camera.hpp"
#include <iostream>

int main() {

  Camera cam1 = Camera();
  cam1.SetCameraZoom(10.f);

  std::cout << CAMERA_ZOOM << "\n";

  EnemyCam enm1 = EnemyCam();
  enm1.SetEnemyCamZoom(22.0f);

  std::cout << CAMERA_ZOOM << "\n";

  return 0;
}
