/**
 * @file stl_transform.cpp
 * @author Wei Du
 *
 * @version 0.1
 * @date 2021-08-18
 */

#include <Eigen/Dense>
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1{};
  Eigen::VectorXd vct(4);
  for (int i = 0; i < 4; ++i) {
    vct(i) = i;
  }
  std::cout << "yeah, succeded\n";
  return 0;
}
