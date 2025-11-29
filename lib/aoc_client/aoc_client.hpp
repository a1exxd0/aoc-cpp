#pragma once

#include <string>

namespace aoc {

class AocClient {
  std::string session_cookie;
  std::uint16_t year;

public:
  explicit AocClient(std::string session_cookie, std::uint16_t year)
      : session_cookie(std::move(session_cookie)), year(year) {}
};

}; // namespace aoc
