/**
 * @file eigen.cpp
 * @author Wei Du
 *
 * @version 0.1
 * @date 2021-08-18
 */

// STL include
#include <array>
#include <cassert>
#include <iostream>

// external include
#include <Eigen/Dense>
#include <Eigen/Geometry>

/*
 * int main() {
 *   //  x, y, z, w
 *   std::array<double, 4> arr{0.3, 0.27, 0, 1.0};
 *   Eigen::Vector4d vct{0.3, 0.27, 0, 1};
 *
 *   // Eigen::Quaterniond quat1(vct(0), vct(1), vct(2), vct(3));
 *   // Eigen::Quaterniond quat2(arr[0], arr[1], arr[2], arr[3]);
 *   Eigen::Quaterniond quat1(vct.data());
 *   Eigen::Quaterniond quat2(arr.data());
 *
 *   printf("should be: %.2f %.2f %.2f %.2f\n", arr[0], arr[1], arr[2], arr[3]);
 *   printf("%.2f %.2f %.2f %.2f\n", quat1.x(), quat1.y(), quat1.z(),
 * quat1.w()); printf("%.2f %.2f %.2f %.2f\n", quat2.x(), quat2.y(), quat2.z(),
 * quat2.w()); return 0;
 * }
 */

/*
 * int main() {
 *   Eigen::VectorXd v1(4);
 *   Eigen::Vector3d v2{0.1, 0.2, 0.3};
 *
 *   v1.head(3) = v2;
 *   v1(3) = 0.8;
 *   std::cout << v1 << std::endl;
 *   return 0;
 * }
 */

/*
int main() {
  Eigen::Vector2d tran{0.2, 0.3};
  Eigen::Rotation2Dd ori(0.785398);

  Eigen::Affine2d pose;
  pose.setIdentity();
  pose.translate(tran);
  pose.rotate(ori);

  Eigen::Vector2d origin{0.1, 0.0};
  Eigen::Vector2d newpt = pose * origin;
  std::cout << newpt << std::endl;
  return 0;
}
*/

/*
int main() {
  Eigen::Vector3d vct1;
  Eigen::VectorXd vct2;
  if (vct1.isApprox(vct2)) {
    printf("they are the same\n");
  } else {
    printf("they are not the same\n");
  }
  std::cout << vct1 << std::endl;

  return 0;
}
*/

/*
 * int main() {
 *   Eigen::MatrixXd mt;
 *   mt.resize(1000, 1000);
 *   mt.fill(-1);
 *   std::cout << mt;
 *   return 0;
 * }
 */

/*
 * int main() {
 *   Eigen::MatrixXd mat(5, 4);
 *   mat << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
 * 20;
 *
 *   std::cout << mat.rows() << std::endl;
 *   mat.conservativeResize(mat.rows() - 2, 3);
 *   std::cout << mat << std::endl;
 *   std::cout << mat.rows() << std::endl;
 *
 *   return 0;
 * }
 */

/*
 * int main() {
 *   const Eigen::Vector3d vec{0, 1, 0};
 *   std::cout << vec << std::endl;
 *   return 0;
 * }
 */

/*
 * int main() {
 *   Eigen::MatrixXd mt(2, 2);
 *   mt << 0, 1, 2, 3;
 *
 *   Eigen::MatrixXd new_mt = mt;
 *   mt(1, 1) = 8;
 *   std::cout << mt << std::endl;
 *   std::cout << new_mt << std::endl;
 *
 *   return 0;
 * }
 */

/*
 * int main() {
 *   auto q =
 *       Eigen::Quaterniond(Eigen::AngleAxisd(0.15, Eigen::Vector3d::UnitX()) *
 *                          Eigen::AngleAxisd(-1.33, Eigen::Vector3d::UnitY()) *
 *                          Eigen::AngleAxisd(1.57, Eigen::Vector3d::UnitZ()));
 *   auto euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
 *   // 0.15 -1.33 1.57
 *   std::cout << euler << std::endl;
 *   return 0;
 * }
 */

int main() {
  Eigen::Vector3d a = Eigen::Vector3d::Random();
  // a.setZero();
  printf("%.2f %.2f %.2f\n", a(0), a(1), a(2));
  a.setRandom();
  printf("%.2f %.2f %.2f\n", a(0), a(1), a(2));
  a.setRandom();
  printf("%.2f %.2f %.2f\n", a(0), a(1), a(2));

  Eigen::Vector3i b;
  b.setZero();
  printf("%d %d %d\n", b(0), b(1), b(2));
  b.setRandom();
  printf("%d %d %d\n", b(0), b(1), b(2));
  return 0;
}
