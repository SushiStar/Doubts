

#include <algorithm>
#include <cmath>
#include <iostream>

/*
 * int main() {
 *   double y = 1.732;
 *   double x = 1;
 *   double theta = std::atan2(y, x) / 3.1415926 * 180;
 *   printf("Theta is: %.3f degrees\n", theta);
 *   return 0;
 * }
 */

/*
 * // compare std swap with tmp swap
 * // conclusion: temp swap is faster than std::swap on integers
 * int main() {
 *   int a = 10;
 *   int b = 11;
 *
 *   for (int i = 0; i < 100000000; ++i) {
 *     int c = a;
 *     a = b;
 *     b = c;
 *   }
 *
 *   return 0;
 * }
 */
