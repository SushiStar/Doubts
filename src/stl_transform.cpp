/**
 * @file stl_transform.cpp
 * @author Wei Du
 *
 * @version 0.1
 * @date 2021-08-18
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

/**
 * std::transform applies the given function to a range and stores the result in
 * another range, keeping the original elements order and beginning at d_first.
 */

int main() {
  std::string s("hello");
  std::transform(
      s.begin(), s.end(), s.begin(),
      [](unsigned char c) -> unsigned char { return std::toupper(c); });

  std::vector<std::size_t> ordinals;
  std::transform(s.begin(), s.end(), std::back_inserter(ordinals),
                 [](unsigned char c) -> std::size_t { return c; });

  std::transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),
                 ordinals.begin(), std::plus<>{});

  std::vector<double> vec1{0, 1, 3, 4, 4, 5, 2, 4, 6, 7, 8, 4, 5};
  std::vector<double> vec2{};
  std::transform(vec1.begin(), vec1.end(), std::back_inserter(vec2),
                 [](double val) { return val * val; });
  for (const double& a : vec2)
    std::cout << a << " ";
  /*
   * auto wrapper = [](double val) { return val + 2.4; };
   * std::transform(vec1.begin(), vec1.end(), vec1.begin(), wrapper);
   * for_each(vec1.begin(), vec1.end(),
   *          [](double val) { std::cout << val << " "; });
   */
}
