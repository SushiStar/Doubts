/**
 */

#include <bitset>
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
  uint32_t a = 17;
  uint32_t b = ~a;
  std::bitset<32> st1(a), st2(b);

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << st1 << std::endl;
  std::cout << st2 << std::endl;
}
