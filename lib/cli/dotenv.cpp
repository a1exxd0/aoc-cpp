#include "lib/cli/dotenv.hpp"

#include <cstdlib>
#include <expected>
#include <filesystem>
#include <format>
#include <fstream>
#include <string>
#include <variant>

namespace aoc::cli {

auto load_dotenv(const std::string &path)
    -> std::expected<std::monostate, std::string> {
  auto abs_path = std::filesystem::absolute(std::filesystem::path(path));
  auto f = std::ifstream(abs_path);
  if (!f) {
    return std::unexpected(std::format(
        "could not find environment file '.env' in {}", abs_path.string()));
  }

  auto line = std::string();
  while (std::getline(f, line)) {
    if (line.empty() || line[0] == '#')
      continue;
    auto pos = line.find('=');
    if (pos == std::string::npos)
      continue;
    auto key = line.substr(0, pos);
    auto val = line.substr(pos + 1);
    setenv(key.c_str(), val.c_str(), 1);
  }

  return {};
}

} // namespace aoc::cli
