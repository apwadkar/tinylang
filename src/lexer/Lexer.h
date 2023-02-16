#ifndef TINYLANG_LEXER_H
#define TINYLANG_LEXER_H

#include <string>
#include <vector>

#include "Tokens.h"

namespace tinylang {

class Lexer
{
public:
  explicit Lexer(std::string input);

  void Lex();
  void Print() const;

private:
  std::string input;
  std::vector<Token> tokens;
};

}// namespace tinylang

#endif// TINYLANG_LEXER_H
