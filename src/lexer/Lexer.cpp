#include <cctype>
#include <fmt/core.h>
#include <iostream>
#include <sstream>
#include <utility>

#include "Lexer.h"

namespace tinylang {

constexpr size_t TOKEN_INIT_RESERVE = 10;

Lexer::Lexer(std::string input) : input(std::move(input)) { tokens.reserve(TOKEN_INIT_RESERVE); }

void Lexer::Lex()
{
  std::stringstream accumulator{};
  TokenType currentType = TokenType::Number;
  for (auto c : input) {
    if (static_cast<bool>(std::isdigit(c)) || c == '.') {
      if (currentType != TokenType::Number) {
        Token token{};
        token.type = currentType;
        token.data = accumulator.str();
        accumulator.clear();
        currentType = TokenType::Number;
      }
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
    }

    accumulator << c;
  }
}

void Lexer::Print() const
{
  for (auto token : tokens) { std::cout << fmt::format(""); }
}

}// namespace tinylang