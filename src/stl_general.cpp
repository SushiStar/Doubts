#include <algorithm>
#include <ctime>
#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <set>
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

/*
 * int main() {
 *   std::unordered_set<int> sett;
 *   sett.insert(3);
 *   sett.insert(4);
 *   sett.insert(5);
 *   sett.insert(6);
 *   sett.erase(7);
 *   return 0;
 * }
 */

/**
 * @brief test lambda as a function parameter
 */
/*
 * class test {
 *  public:
 *   void Add(int a, int b);
 * };
 *
 * void test::Add(int a, int b) {
 *   throw std::runtime_error("throwed an error");
 *   std::cout << a + b << std::endl;
 * }
 *
 * bool exception_test(std::function<void()> f) {
 *   bool exception_flag{false};
 *   try {
 *     f();
 *   } catch (std::runtime_error &e) {
 *     exception_flag = true;
 *   }
 *   return exception_flag;
 * }
 */

/*
 * int main() {
 *   test t;
 *   std::function<void()> f = [&]() { t.Add(10, 20); };
 *   if (exception_test(f)) {
 *     printf("exception caught!\n");
 *   } else {
 *     printf("exception not caught!\n");
 *   }
 *   return 0;
 * }
 */

/*
 * int main() {
 *   std::vector<int> vct{0, 1, 2, 3};
 *   for_each(vct.begin(), vct.end(), [&](int& i) { ++i; });
 *   for_each(vct.begin(), vct.end(), [&](int i) { std::cout << i << '\n'; });
 *
 *   return 0;
 * }
 */

/*
 * class A {
 *  public:
 *   A(int k);
 *   bool SameVal(const A &other);
 *
 *  private:
 *   int val;
 * };
 *
 * A::A(int k) : val(k) {
 * }
 *
 * bool A::SameVal(const A &other) {
 *   return val == other.val;
 * }
 *
 * int main() {
 *   A a(10);
 *   A b(11);
 *   if (a.SameVal(b)) {
 *     printf("same value\n");
 *   } else {
 *     printf("different value\n");
 *   }
 *   return 0;
 * }
 */
/*
 * int main() {
 *   std::vector<int> vct;
 *   bool ret = std::all_of(vct.begin(), vct.end(), [](int a) { return true; });
 *   printf(ret ? "true\n" : "false\n");
 *
 *   return 0;
 * }
 */

/**
 * @brief list initialization test
 *
 * @return
 */

/*
 * class Box {
 *  public:
 *   Box(double x, double y, double z) : x_(x), y_(y), z_(z) {
 *   }
 *
 *   friend std::ostream& operator<<(std::ostream& os, const Box& box);
 *
 *  private:
 *   double x_, y_, z_;
 * };
 *
 * std::ostream& operator<<(std::ostream& os, const Box& box) {
 *   std::cout << box.x_ << " " << box.y_ << " " << box.z_ << std::endl;
 *   return os;
 * }
 *
 * int main() {
 *   Box box{1, 2, 3};
 *   std::cout << box << std::endl;
 *   return 0;
 * }
 */

/*
 * int main() {
 *   std::vector<std::string> vec{"a,", "bs",   "csd",  "dd",     "ee",
 *                                "df", "sadf", "asdf", "asdfll", "sdf;low"};
 *
 *   std::unordered_set<std::string> sett{
 *       "a,", "bs", "csd", "dd", "ee", "df", "sadf", "asdf", "asdfll", "sdf;low"};
 *
 *   clock_t begin = clock();
 *   for (int i = 0; i < 100000; ++i) {
 *     vec.emplace_back("regional");
 *     vec.emplace_back("non_regional");
 *     auto it = std::remove(vec.begin(), vec.end(), "regional");
 *     vec.erase(it);
 *     vec.pop_back();
 *   }
 *   clock_t end = clock();
 *   double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
 *   std::cout << "vec took time: " << elapsed_secs << " seconds\n";
 *
 *   begin = clock();
 *   for (int i = 0; i < 100000; ++i) {
 *     sett.insert("regional");
 *     sett.insert("non_regional");
 *     sett.erase("regional");
 *     sett.erase("non_regional");
 *   }
 *   end = clock();
 *   elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
 *   std::cout << "set took time: " << elapsed_secs << " seconds\n";
 *
 *   return 0;
 * }
 */

// int main() {
//     std::vector<int> vec{1, 2, 3, 4, 5};
//     auto it = vec.begin();
//     auto another = std::prev(it);
//     if (another == vec.end()) {
//         printf("true\n");
//     } else {
//         printf("%d\n", *another);
//     }
//     return 0;
// }

// int main() {
//   std::multiset<int> sett;
//   sett.insert(0);
//   sett.insert(1);
//   sett.insert(0);
//   sett.erase(sett.find(0));
//   sett.erase(sett.find(0));
//   for (auto v : sett) {
//     std::cout << v << std::endl;
//   }
// }

class Foo {
 public:
  virtual void SayHi() = 0;
  virtual ~Foo(){};
};

class Point {
 public:
  int x{0};
  int y{0};
};

template <class T>
class Bar : public Foo {
 public:
  virtual ~Bar(){};
  Point pt;
  virtual void SayHi() {
    printf("hi\n");
  }
};

int main() {
  std::unique_ptr<Foo> talker = std::make_unique<Bar<Point>>();
  talker->SayHi();
  return 0;
}

// class Foo {
//  public:
//   virtual void SayHi() = 0;
//   virtual ~Foo(){};
// };

// class Bar : public Foo {
//  public:
//   ~Bar(){};
//   virtual void SayHi() {
//     printf("hi\n");
//   }
// };

// int main() {
//   std::unique_ptr<Foo> talker = std::make_unique<Bar>();
//   return 0;
// }