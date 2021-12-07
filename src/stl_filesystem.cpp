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

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// int main() {
//   std::string directory{"/home/w/Downloads/"};
//   std::string extension{".log"};
//   for (const auto& p : std::filesystem::directory_iterator(directory)) {
//     if (p.path().extension() == extension)
//       std::cout << p.path().stem() << std::endl;
//   };
// }

int main() {
  std::string filepath{"/home/w/Downloads/cat_driver.log"};
  //{"timestamp":"2021-11-09T11:10:29.137453-08:00",
  //"message":"pressure_reading",
  //"extra":{"cup":5,"error_delay":0,"pressure":0.0,"state":1}}
  // const char fmt[] = "{\"timestamp\":\"%s\"[, ]\"message\":\"%s\"[, ]%s}";
  // const char fmt[] = "{\"timestamp\":\"%[^\"]%[^,] \"message\":%[^\",], %s}";
  const char fmt[] = "{\"%[^\"]\":\"%[^\"]\", \"%[^\"]\":\"%[^\"]\", %s}";
  std::fstream fs(filepath);
  std::string buffer;
  char timestamp[10], stamp[50], message[50], msg[50], tmp[4096];
  while (std::getline(fs, buffer)) {
    std::sscanf(buffer.c_str(), fmt, timestamp, stamp, message, msg, tmp);
    std::cout << stamp << " " << msg << " " << tmp << std::endl;
    // if () {
    // std::cout << buffer;
    // }
  }

  return 0;
}

// int main() {
//   std::string s{"12 message34, 56 6"};
//   constexpr char fmt[] = "%s message%[^','], %s %s";
//   char one[10], two[20], three[30], four[40];
//   std::sscanf(s.c_str(), fmt, one, two, three, four);
//   std::cout << one << " " << two << " " << three << " " << four << '\n';
//   return 0;
// }
