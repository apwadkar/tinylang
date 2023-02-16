#include "lexer/Lexer.h"

using namespace tinylang;

int main()
{
  Lexer lexer{ "10 + 1" };
  lexer.Lex();
  lexer.Print();

  return 0;
}
