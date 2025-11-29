#pragma once

#include <expected>
#include <string>
#include <variant>

namespace aoc::cli {

/// Load local dotenv file, defaulting to `$(pwd)/.env`
[[nodiscard]] auto load_dotenv(const std::string &path = ".env")
    -> std::expected<std::monostate, std::string>;

} // namespace aoc::cli
