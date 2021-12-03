/**
 * @file string.cpp
 * @author Wei Du
 *
 * @version 0.1
 * @date 2021-08-18
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

std::string InvalidIDMsg(const char* func, int id) {
  return std::string(func) + ": Invalid ID: " + std::to_string(id);
}

class A {
 public:
  void say() {
    throw std::runtime_error(InvalidIDMsg(__PRETTY_FUNCTION__, 10));
  }
};

/// @brief test string_view
int main() {
  std::string st{"0123456789"};
  std::string_view stv{st.substr(0, 3)};
  std::cout << stv << std::endl;
  st[0] = 9;
  std::cout << stv << std::endl;
  return 0;
}

/// @brief string_view == string ?
/// implicit from string to string_view
// int main() {
//   std::string st{"01234"};
//   std::string_view stv{"01234"};
//   if (st == stv) {
//     std::cout << "equal\n";
//   } else {
//     std::cout << "unequal\n";
//   }
//   return 0;
// }

/// @brief implicit conversion from string_view to string
/// Answer: failure
// void SomeFunc(const std::string& s) {
//   std::cout << s << std::endl;
// }

// int main() {
//   const std::string_view sv{"asldkfj;LSDJKf"};
//   SomeFunc(sv);
//   return 0;
// }
