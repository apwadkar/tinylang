#include <cctype>
#include <fmt/core.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include <sstream>
#include <utility>

#include "Lexer.h"

namespace tinylang {

Lexer::Lexer(std::string inputStr) : input(std::move(inputStr)) {}

void Lexer::Lex()
{
  std::stringstream accumulator{};
  TokenType currentType = TokenType::Number;
  for (auto inputChar : input) {
    auto expectedType = Token::ExpectedTokenType(inputChar);
    if (currentType != expectedType && expectedType != TokenType::Invalid) {
      tokens.emplace_back(CreateToken(accumulator.str(), currentType));
      accumulator.str({});
      currentType = expectedType;
    } else if (expectedType == TokenType::Invalid) {
      continue;
    }

    accumulator << inputChar;
  }
  tokens.emplace_back(CreateToken(accumulator.str(), currentType));
}

void Lexer::Print() const
{
  for (const auto &token : tokens) { spdlog::info(token.String()); }
}

Token Lexer::CreateToken(std::string strData, TokenType tokenType)
{
  Token token{};
  switch (tokenType) {
  case TokenType::Operator:
    token.type = tokenType;
    token.data = OperatorType{ strData[0] };
    break;
  case TokenType::Number:
    token.type = tokenType;
    token.data.emplace<double>(strtod(strData.c_str(), nullptr));
    break;
  default:
    break;
  }
  return token;
}

}// namespace tinylang