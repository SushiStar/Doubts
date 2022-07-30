

#include <algorithm>
#include <cmath>
#include <iostream>

#define SWAP(a, b) \
  {                \
    int temp{a};   \
    a = b;         \
    b = temp;      \
  }

/*
 * int main() {
 *   double y = 1.732;
 *   double x = 1;
 *   double theta = std::atan2(y, x) / 3.1415926 * 180;
 *   printf("Theta is: %.3f degrees\n", theta);
 *   return 0;
 * }
 */

// compare std swap with tmp swap
// conclusion: temp swap is faster than std::swap on integers
/*
 * int main() {
 *   for (int i = 0; i < 100000000; ++i) {
 *     int a = 13;
 *     int b = 11;
 *     int sm{a + b};
 *     a = a < b ? a : b;
 *     b = sm - a;
 *   }
 *   return 0;
 * }
 */

// cast double to int
/*
 * int main() {
 *   double val = 0.9999999;
 *   int valI = static_cast<int>(std::round(val));
 *   printf("%.15f, %d\n", round(val), valI);
 * }
 */

int main() {
    int i = 4; 
    i >>= 10;
    std::cout << i << std::endl;
    return 0;
}
