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
  Eigen::MatrixXd points(3, 6);
  points << -0.0048, 0.3527, 1.7433, 0.3484, 0.4033, 2.6894, 0.3617, 0.4069,
      2.7053, 0.4015, 0.4141, 2.7372, 0.5512, 0.4302, 2.7407, 0.6452, 0.4433,
      2.6487;
  return points;
}

int main() {
  const Eigen::DenseIndex degree{3};
  const auto pts = GetWayPoints();
  Eigen::Spline3d::KnotVectorType chord_lengths;  // knot parameters
  Eigen::ChordLengths(pts, chord_lengths);

  Eigen::Spline3d spl = Eigen::SplineFitting<Eigen::Spline3d>::Interpolate(
      pts, degree, chord_lengths);

  for (Eigen::DenseIndex i = 0; i < pts.cols(); ++i) {
    Eigen::Spline3d::PointType pt = spl(chord_lengths(i));
    Eigen::Spline3d::PointType ref = pts.col(i);
    printf("%.3f %.3f %.3f <-> %.3f %.3f %.3f\n", pt(0), pt(1), pt(2), ref(0),
           ref(1), ref(2));
  }

  return 0;
}