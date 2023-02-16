#ifndef TINYLANG_TOKENS_H
#define TINYLANG_TOKENS_H

#include <fmt/core.h>
#include <string>

namespace tinylang {

enum class TokenType {
  Number,// -?[0-9]+(.[0-9]*)?
  Operator// [+-*/]
};

struct Token
{
  TokenType type;
  std::string data;

  virtual std::string String()
  {
    switch (type) {
    case TokenType::Number:
      return "NUMBER";
    case TokenType::Operator:
      return "OPERATOR";
    }
  };

  virtual ~Token() = default;
};

// Real numbers
struct Number : Token
{
  double value;

  std::string String() final { return fmt::format("NUMBER: {}", value); }
};

// Mathematical operators
struct Operator : Token
{
  enum class OperatorType { Add, Subtract, Multiply, Divide } operatorType;

  std::string String() final
  {
    auto str = "";
    switch (operatorType) {
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
    return fmt::format("{}: {}", Token::String(), str);
  }
};

}// namespace tinylang

#endif// TINYLANG_TOKENS_H
