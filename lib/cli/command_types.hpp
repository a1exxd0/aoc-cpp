namespace aoc {

/// Different run options
enum class CommandTypes {
  /// Generate base code to write solutions into
  Scaffold,

  /// Download problem inputs (both examples and full)
  Download,

  /// Run solution over full input
  Solve,

  /// Run solution over examples
  Test,

  /// Benchmark solution over full input
  Time,
};

} // namespace aoc
