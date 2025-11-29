#include "lib/aoc_client/aoc_client.hpp"

#include <algorithm>
#include <cctype>
#include <expected>
#include <format>
#include <string>

namespace aoc {

auto AocClient::build_client(std::string session_cookie, std::uint16_t year)
    -> std::expected<AocClient, std::string> {
  if (session_cookie.empty() || std::ranges::any_of(session_cookie, [](char c) {
        return !std::isxdigit(c);
      })) {
    return std::unexpected(
        std::format("invalid session cookie found: {}", session_cookie));
  }
}

}; // namespace aoc
