#include <CLI/CLI.hpp>
#include <string_view>

#include "lib/cli/app.hpp"
#include <cassert>
#include <format>

namespace aoc {
namespace cli {

auto build_cli(CLI::App &app, std::string_view cookie, std::uint16_t year)
    -> void {
  app.name("aoc-cpp");
  app.description(std::format("Advent of Code for C++, year {}", year));

  auto scaffold = app.add_subcommand(
      "scaffold",
      "Generate template code to write solutions into for input day");
  auto download = app.add_subcommand(
      "download", "Download problem inputs and solutions for input day");
  auto solve = app.add_subcommand(
      "solve", "Run solution for input day against full input");
  auto test = app.add_subcommand(
      "test", "Run solution for input day against example input");
  auto time = app.add_subcommand(
      "time", "Benchmark solutions for input day against full input");

  // no nullpointers!
  assert(scaffold && download && solve && test && time);
}

} // namespace cli
} // namespace aoc
