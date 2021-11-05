/**
 */

#include <iostream>
#include <vector>

/*
 * int main() {
 *   // bit operation on double --> not allowed
 *   double a{3.0};
 *   double b{a >> 2};
 *   printf("a is %.4f, b is %.4f\n", a, b);
 *   return 0;
 * }
 */

int main() {
  int a = 11;
  int b = a + 1;
  int c = a ^ b;
  std::cout << c << std::endl;
}
