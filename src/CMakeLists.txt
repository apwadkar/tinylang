find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(tinylib lexer/Lexer.cpp lexer/Lexer.h lexer/Tokens.h)
target_link_libraries(
  tinylib
  PUBLIC project_options project_warnings
  PRIVATE fmt::fmt spdlog::spdlog)

add_executable(tinylang main.cpp)
target_link_libraries(
  tinylang
  PUBLIC tinylib project_options project_warnings
  PRIVATE fmt::fmt spdlog::spdlog)
