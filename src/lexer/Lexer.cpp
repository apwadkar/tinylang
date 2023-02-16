#include <cctype>
#include <fmt/core.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include <sstream>
#include <utility>

#include "Lexer.h"

namespace tinylang {

constexpr size_t TOKEN_INIT_RESERVE = 10;

Lexer::Lexer(std::string input) : input(std::move(input)), tokens(TOKEN_INIT_RESERVE) {}

void Lexer::Lex()
{
  std::stringstream accumulator{};
  TokenType currentType = TokenType::Number;
  for (auto c : input) {
    if (static_cast<bool>(std::isdigit(c)) || c == '.') {
      if (currentType != TokenType::Number) {
        Token token{};
        token.type = currentType;
        token.data = OperatorType{ c };
        accumulator.clear();
        currentType = TokenType::Operator;
        tokens.emplace_back(token);
      }
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      if (currentType != TokenType::Operator) {
        Token token{};
        token.type = currentType;
        auto str = accumulator.str();
        token.data.emplace<double>(strtod(str.c_str(), nullptr));
        accumulator.clear();
        currentType = TokenType::Number;
        tokens.emplace_back(token);
      }
    } else {
      continue;
    }

    accumulator << c;
  }
}

void Lexer::Print() const
{
  for (const auto &token : tokens) { spdlog::info(token.String()); }
}

}// namespace tinylang