#include <CLI/CLI.hpp>

#include "lib/cli/app.hpp"
#include "lib/cli/dotenv.hpp"

auto main(int argc, char **argv) -> int {
  auto load_env_success = aoc::cli::load_dotenv();
  if (!load_env_success) {
    std::println(stderr, "{}", load_env_success.error());
    return -1;
  }

  auto cookie = std::getenv("AOC_SESSION_COOKIE");
  auto year = std::getenv("AOC_YEAR");
  auto app = CLI::App();
  auto parsedYear = atoi(year);
  if (parsedYear < 1900 ||
      parsedYear > std::numeric_limits<std::uint16_t>::max()) {
    std::println(stderr, "{} was not a valid year for the variable AOC_YEAR",
                 year);
  }

  aoc::cli::build_cli(app, cookie, static_cast<uint16_t>(parsedYear));

  CLI11_PARSE(app, argc, argv);
  return 0;
}
