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
  Eigen::MatrixXd points(6, 3);
  points << -0.0048, 0.3527, 1.7433,  //
      0.3484, 0.4033, 2.6894,         //
      0.3617, 0.4069, 2.7053,         //
      0.4015, 0.4141, 2.7372,         //
      0.5512, 0.4302, 2.7407,         //
      0.6452, 0.4433, 2.6487;

  std::cout << points << std::endl;

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
      points, 4, chord_lengths);

  std::vector<Eigen::Vector3d> ret{};
  for (double i = 0; i < 1.0; i += step) {
    Eigen::MatrixXd deriv = spln.derivatives(i, 2);
    auto pt{deriv.col(0)};
    printf("%.5f %.5f %.5f\n", pt(0), pt(1), pt(2));
  }
  return ret;
}
