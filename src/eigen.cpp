/**
 * @file eigen.cpp
 * @author Wei Du
 *
 * @version 0.1
 * @date 2021-08-18
 */

// STL include
#include <array>
#include <iostream>

// external include
#include <Eigen/Dense>
#include <Eigen/Geometry>

int main() {
  //  x, y, z, w
  std::array<double, 4> arr{0.3, 0.27, 0, 1.0};
  Eigen::Vector4d vct{0.3, 0.27, 0, 1};

  // Eigen::Quaterniond quat1(vct(0), vct(1), vct(2), vct(3));
  // Eigen::Quaterniond quat2(arr[0], arr[1], arr[2], arr[3]);
  Eigen::Quaterniond quat1(vct.data());
  Eigen::Quaterniond quat2(arr.data());

  printf("should be: %.2f %.2f %.2f %.2f\n", arr[0], arr[1], arr[2], arr[3]);
  printf("%.2f %.2f %.2f %.2f\n", quat1.x(), quat1.y(), quat1.z(), quat1.w());
  printf("%.2f %.2f %.2f %.2f\n", quat2.x(), quat2.y(), quat2.z(), quat2.w());
  return 0;
}
