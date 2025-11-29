# Advent of Code template for C++

This takes heavy inspiration from Felix Spöttel's [advent-of-code-rust](https://github.com/fspoettel/advent-of-code-rust/) implementation!

# Development

Build the repository:

```
bazel build //...
```

Or if you want to build for release:

```
bazel build --compilation_mode=opt //...
```

Run the binary. Note that running the binary via the `bazel run` command will throw errors on accessing the dotenv file.

```
bazel-bin/src/aoc-cpp
```

Refresh your `compile_commands.json`:

```
bazel run :refresh_compile_commands
```
