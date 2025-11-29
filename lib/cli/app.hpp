#pragma once
#include <CLI/CLI.hpp>

namespace aoc {
namespace cli {

/// Build the CLI for an app with no changes.
///
/// Need this because of deleted copy & move constructors for CLI::App.
auto build_cli(CLI::App &app, std::string_view cookie, std::uint16_t year)
    -> void;

} // namespace cli
} // namespace aoc
