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

std::string InvalidIDMsg(const char* func, int id) {
  return std::string(func) + ": Invalid ID: " + std::to_string(id);
}

class A {
 public:
  void say() {
    throw std::runtime_error(InvalidIDMsg(__PRETTY_FUNCTION__, 10));
  }
};

int main() {
  int a = 3;
  std::string output("salfkjas;ld |");
  std::string kk(output + char('a' + a));
  A sayer;
  sayer.say();
  return 0;
}
