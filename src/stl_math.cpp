

#include <cmath>
#include <iostream>

int main() {
  double y = 1.732;
  double x = 1;
  double theta = std::atan2(y, x) / 3.1415926 * 180;
  printf("Theta is: %.3f degrees\n", theta);
  return 0;
}
