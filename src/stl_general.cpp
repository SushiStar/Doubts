#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> v2{8, 9};

  v2.insert(v2.end(), v1.begin() + 1, v1.begin() + 2);
  for (auto i : v2) {
    std::cout << i << ", ";
  }
  printf("\n");

  return 0;
}
