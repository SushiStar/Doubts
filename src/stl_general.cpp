#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
/*
 * int main() {
 *   const std::string test{"sldfkj"};
 *   auto lmd = [&test](int idx) -> std::string {
 *     return test + "2" + std::to_string(idx);
 *   };
 *   std::cout << lmd(3) << std::endl;
 * }
 */

/*
 * int main() {
 *   std::vector<std::string> vct1{"1", "2", "3", "3"};
 *   std::vector<std::string> vct2{"3", "4", "4", "5"};
 *   std::unordered_set<std::string> sett;
 *   sett.insert(vct1.begin(), vct1.end());
 *   sett.insert(vct2.begin(), vct2.end());
 *   for (auto num : sett) {
 *     std::cout << num << '\n';
 *   }
 *
 *   return 0;
 * }
 */

/*
 * int main() {
 *   std::unique_ptr<int> a = std::make_unique<int>(10);
 *   std::cout << *a << std::endl;
 *   auto& b = a;
 *   std::cout << *b << std::endl;
 *   *b = 2;
 *   std::cout << *a << std::endl;
 * }
 */

int main() {
  std::unordered_set<int> sett;
  sett.insert(3);
  sett.insert(4);
  sett.insert(5);
  sett.insert(6);
  sett.erase(7);
  return 0;
}
