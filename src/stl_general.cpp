#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * int main() {
 *   std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
 *   std::vector<int> v2{8, 9};
 *
 *   v2.insert(v2.end(), v1.begin() + 1, v1.begin() + 2);
 *   for (auto i : v2) {
 *     std::cout << i << ", ";
 *   }
 *   printf("\n");
 *
 *   return 0;
 * }
 */

/*
 * int main() {
 *   std::unordered_map<std::string, uint32_t> mp;
 *   std::cout << mp["asldfkj"] << std::endl;
 *   std::cout << mp["asldkfja"] << std::endl;
 * }
 */

// conclusion: lambda capture is const by default
int main() {
  const std::string test{"sldfkj"};
  auto lmd = [&test](int idx) -> std::string {
    return test + "2" + std::to_string(idx);
  };
  std::cout << lmd(3) << std::endl;
}
