find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# Generic test that uses conan libs
add_executable(tinylang main.cpp lexer/Lexer.cpp)
target_link_libraries(
  tinylang
  PUBLIC project_options project_warnings
  PRIVATE fmt::fmt spdlog::spdlog)
