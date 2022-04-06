#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class A {
 public:
  int val{10};
};

class B : public A {
 public:
  int val_val{11};
};

/*
 * int main() {
 *   std::unique_ptr<A> ptr{nullptr};
 *   std::unique_ptr<B> ptrr = std::make_unique<B>();
 *   ptrr->val = 11;
 *   ptr = std::move(ptrr);
 *   std::cout << ptr->val << std::endl;
 *   return 0;
 * }
 */

int main() {
  std::shared_ptr<int> ptr1 = std::make_shared<int>(3);
  std::shared_ptr<int> ptr2(ptr1);
  if (ptr2 == ptr1) {
    printf("equal\n");
  } else {
    printf("not equal\n");
  }
  std::unordered_set<std::shared_ptr<int>> sett{ptr1};
  if (sett.count(ptr2)) {
    printf("same hash\n");
  }
  return 0;
}
