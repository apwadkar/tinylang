#include <spdlog/spdlog.h>

#include "lexer/Lexer.h"

using namespace tinylang;

int main()
{
  // Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {}!", "World");

  Lexer lexer{ "10 + 1" };

  return 0;
}
