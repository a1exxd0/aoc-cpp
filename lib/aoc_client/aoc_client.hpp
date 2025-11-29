#pragma once

#include <expected>
#include <string>

namespace aoc {

static constexpr auto AOC_URL = "https://adventofcode.com";

class AocClient {
  std::string session_cookie;
  std::uint16_t year;

  explicit AocClient(std::string session_cookie, std::uint16_t year)
      : session_cookie(std::move(session_cookie)), year(year) {}

public:
  /// Build a client and return an error if sanity checks fail
  static auto build_client(std::string session_cookie, std::uint16_t year)
      -> std::expected<AocClient, std::string>;

  /// Get input for a given day
  auto get_full_input(std::uint8_t day)
      -> std::expected<std::string, std::string>;

  friend class AocClientBuilder;
};

}; // namespace aoc
