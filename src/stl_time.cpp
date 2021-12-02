#include <chrono>
#include <cstdio>  // sscanf
#include <cstring>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>

// ParseISO8601 returns milliseconds since 1970
std::time_t ParseISO8601(const std::string& input) {
  constexpr char example[] = "2021-07-08T11:00:00.000943-08:00";
  constexpr char format[] = "%d-%d-%dT%d:%d:%d.%d-%d:%d";
  const size_t expectedLength = std::strlen(example);

  if (input.size() != expectedLength)
    throw std::runtime_error("Invalid time format.");

  int year, month, day, hour, minute, second, microsecond;
  int hour_zone, minute_zone;  // place holder
  std::tm time_info;
  sscanf(input.c_str(), format, &time_info.tm_year, &time_info.tm_mon,
         &time_info.tm_mday, &time_info.tm_hour, &time_info.tm_min,
         &time_info.tm_sec, &microsecond, &hour_zone, &minute_zone);
  // std::cout << time_info.tm_year << "  " << time_info.tm_mon << " "
  //           << time_info.tm_mday << " " << time_info.tm_hour << "  "
  //           << time_info.tm_min << "\n";
  // return static_cast<size_t>(std::mktime(&time_info));
  time_info.tm_year -= 1900;
  time_info.tm_mon -= 1;
  return std::mktime(&time_info);
}

/// \@brief parse iso 8601 to time since epoch
int main() {
  // const std::string datetime{"1970-01-01T00:00:00.008943-07:00"};
  const std::string datetime1{"2021-07-08T11:00:00.008943-07:00"};
  const std::string datetime2{"2021-05-08T11:00:00.008943-07:00"};
  auto a = ParseISO8601(datetime1);
  auto b = ParseISO8601(datetime2);
  std::cout << a << "\n";
  std::cout << b << "\n";
  if (a < b) {
    std::cout << "a < b\n";
  } else {
    std::cout << "a > b\n";
  }
  return 0;
}
