#ifndef TINYLANG_TOKENS_H
#define TINYLANG_TOKENS_H

#include <fmt/core.h>
#include <string>
#include <variant>

namespace tinylang {

enum class TokenType {
  Invalid,
  Number,// -?[0-9]+(.[0-9]*)?
  Operator// [+-*/]
};

enum class OperatorType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

struct Token
{
  using TokenData = std::variant<double, OperatorType>;

  TokenType type;
  TokenData data;

  std::string String() const
  {
    switch (type) {
    case TokenType::Number:
      return fmt::format("NUMBER: {}", std::get<double>(data));
    case TokenType::Operator: {
      auto str = "";
      switch (std::get<OperatorType>(data)) {
      case OperatorType::Add:
        str = "+";
        break;
      case OperatorType::Subtract:
        str = "-";
        break;
      case OperatorType::Multiply:
        str = "*";
        break;
      case OperatorType::Divide:
        str = "/";
        break;
      }
      return fmt::format("OPERATOR: {}", str);
    }
    default:
      return "INVALID TOKEN TYPE";
    }
  }

  static TokenType ExpectedTokenType(char inputChar)
  {
    if (static_cast<bool>(std::isdigit(inputChar)) || inputChar == '.') {
      return TokenType::Number;
    } else if (inputChar == '+' || inputChar == '-' || inputChar == '*' || inputChar == '/') {
      return TokenType::Operator;
    }
    return TokenType::Invalid;
  }
};

}// namespace tinylang

#endif// TINYLANG_TOKENS_H
