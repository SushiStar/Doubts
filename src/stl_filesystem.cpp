/**
 * @file stl_filesystem.cpp
 * @author Wei Du (wweeii.du@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-12-02
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string directory{"/home/w/Downloads/"};
  std::string extension{".log"};
  for (const auto& p : std::filesystem::directory_iterator(directory)) {
    if (p.path().extension() == extension)
      std::cout << p.path().stem() << std::endl;
  };
}
