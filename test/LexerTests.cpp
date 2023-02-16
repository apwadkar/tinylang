#include <catch2/catch_test_macros.hpp>

#include <lexer/Lexer.h>
#include <lexer/Tokens.h>

using namespace tinylang;

TEST_CASE("Lexer should create tokens for simple number", "[lexer]")
{
  Lexer lexer{ "10" };
  lexer.Lex();

  auto tokens = lexer.Tokens();

  REQUIRE(tokens.size() == 1);

  REQUIRE(tokens[0].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[0].data) == 10);
}

TEST_CASE("Lexer should create tokens for simple add", "[lexer]")
{
  Lexer lexer{ "10 + 1" };
  lexer.Lex();

  auto tokens = lexer.Tokens();

  REQUIRE(tokens.size() == 3);

  REQUIRE(tokens[0].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[0].data) == 10);

  REQUIRE(tokens[1].type == TokenType::Operator);
  REQUIRE(std::get<OperatorType>(tokens[1].data) == OperatorType::Add);

  REQUIRE(tokens[2].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[2].data) == 1);
}

TEST_CASE("Lexer should create tokens for simple subtract", "[lexer]")
{
  Lexer lexer{ "10 - 1" };
  lexer.Lex();

  auto tokens = lexer.Tokens();

  REQUIRE(tokens.size() == 3);

  REQUIRE(tokens[0].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[0].data) == 10);

  REQUIRE(tokens[1].type == TokenType::Operator);
  REQUIRE(std::get<OperatorType>(tokens[1].data) == OperatorType::Subtract);

  REQUIRE(tokens[2].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[2].data) == 1);
}

TEST_CASE("Lexer should create tokens for simple multiply", "[lexer]")
{
  Lexer lexer{ "10 * 1" };
  lexer.Lex();

  auto tokens = lexer.Tokens();

  REQUIRE(tokens.size() == 3);

  REQUIRE(tokens[0].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[0].data) == 10);

  REQUIRE(tokens[1].type == TokenType::Operator);
  REQUIRE(std::get<OperatorType>(tokens[1].data) == OperatorType::Multiply);

  REQUIRE(tokens[2].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[2].data) == 1);
}

TEST_CASE("Lexer should create tokens for simple divide", "[lexer]")
{
  Lexer lexer{ "10 / 1" };
  lexer.Lex();

  auto tokens = lexer.Tokens();

  REQUIRE(tokens.size() == 3);

  REQUIRE(tokens[0].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[0].data) == 10);

  REQUIRE(tokens[1].type == TokenType::Operator);
  REQUIRE(std::get<OperatorType>(tokens[1].data) == OperatorType::Divide);

  REQUIRE(tokens[2].type == TokenType::Number);
  REQUIRE(std::get<double>(tokens[2].data) == 1);
}