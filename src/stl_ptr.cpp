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
  std::unique_ptr<int> uptr{new int{10}};
  int* rptr = uptr.get();
}
