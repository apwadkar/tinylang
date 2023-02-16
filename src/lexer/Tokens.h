#ifndef TINYLANG_TOKENS_H
#define TINYLANG_TOKENS_H

#include <fmt/core.h>
#include <string>
#include <variant>

namespace tinylang {

enum class TokenType {
  Number,// -?[0-9]+(.[0-9]*)?
  Operator// [+-*/]
};

enum class OperatorType : char { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

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
    case TokenType::Operator:
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
  }
};

}// namespace tinylang

#endif// TINYLANG_TOKENS_H
