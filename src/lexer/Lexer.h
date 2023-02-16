#ifndef TINYLANG_LEXER_H
#define TINYLANG_LEXER_H

#include <string>
#include <vector>

#include "Tokens.h"

namespace tinylang {

class Lexer
{
public:
  explicit Lexer(std::string inputStr);

  void Lex();
  void Print() const;

  auto Tokens() const { return tokens; }

private:
  static Token CreateToken(std::string strData, TokenType tokenType);

  std::string input;
  std::vector<Token> tokens;
};

}// namespace tinylang

#endif// TINYLANG_LEXER_H
