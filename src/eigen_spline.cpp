/**
 * @file eigen_spline.cpp
 * @author Wei Du (wweeii.du@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-09-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <Eigen/Dense>
#include <iostream>
#include <unsupported/Eigen/Splines>
#include <vector>

/**
 * @brief Get the Way Points object
 *    -0.0048 0.3527 1.7433
 *     0.3484 0.4033 2.6894
 *     0.3617 0.4069 2.7053
 *     0.4015 0.4141 2.7372
 *     0.5512 0.4302 2.7407
 *     0.6452 0.4433 2.6487
 *
 * @return const Eigen::MatrixXd
 */
const Eigen::MatrixXd GetWayPoints() {
  Eigen::MatrixXd points(14, 3);
  /*
  points << -0.0048, 0.3527, 1.7433,  //
      0.3484, 0.4033, 2.6894,         //
      0.3617, 0.4069, 2.7053,         //
      0.4015, 0.4141, 2.7372,         //
      0.5512, 0.4302, 2.7407,         //
      0.6452, 0.4433, 2.6487;
      */
  points << 0.0393, 0.3409, 1.8694, 0.0834, 0.3719, 1.9955, 0.1274, 0.403,
      2.1215, 0.1715, 0.4341, 2.2476, 0.2156, 0.4651, 2.3737, 0.2597, 0.4962,
      2.4998, 0.3037, 0.5272, 2.6258, 0.3478, 0.5583, 2.7519, 0.4344, 0.6007,
      2.748, 0.5209, 0.6431, 2.7441, 0.6075, 0.6854, 2.7402, 0.6941, 0.7278,
      2.7362, 0.7644, 0.7812, 2.6921, 0.8347, 0.8346, 2.6479;

  std::cout << points << "\n\n";

  points.transposeInPlace();
  return points;
}

std::vector<Eigen::Vector3d> splineFromWayPoints(const Eigen::MatrixXd &points);

int main() {
  auto pts_spln = splineFromWayPoints(GetWayPoints());
  return 0;
}

std::vector<Eigen::Vector3d> splineFromWayPoints(
    const Eigen::MatrixXd &points) {
  assert(points.rows() == 3);
  const double step{0.01};
  const unsigned int degree{4};  /// degree of the spline

  // normlaized knot parameters
  Eigen::Spline3d::KnotVectorType chord_lengths;
  Eigen::ChordLengths(points, chord_lengths);

  Eigen::Spline3d spln = Eigen::SplineFitting<Eigen::Spline3d>::Interpolate(
      points, degree, chord_lengths);

  std::vector<Eigen::Vector3d> ret{};
  for (double i = 0; i < 1.0; i += step) {
    Eigen::MatrixXd deriv = spln.derivatives(i, 2);
    auto pt{deriv.col(0)};
    printf("%.5f %.5f %.5f\n", pt(0), pt(1), pt(2));
  }
  return ret;
}
