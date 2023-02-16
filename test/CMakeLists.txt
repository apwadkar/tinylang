cmake_minimum_required(VERSION 3.15...3.23)

project(CmakeConfigPackageTests LANGUAGES CXX)

# ---- Test as standalone project the exported config package ----

if(PROJECT_IS_TOP_LEVEL OR TEST_INSTALLED_VERSION)
  enable_testing()

  find_package(tinylang CONFIG REQUIRED) # for intro, project_options, ...

  if(NOT TARGET tinylang::project_options)
    message(FATAL_ERROR "Requiered config package not found!")
    return() # be strictly paranoid for Template Janitor github action! CK
  endif()
endif()

# ---- Dependencies ----

find_package(Catch2 3 REQUIRED)

include(Catch)

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(LexerTests LexerTests.cpp)
target_link_libraries(
  LexerTests
  PUBLIC tinylib
  PRIVATE tinylang::project_warnings tinylang::project_options Catch2::Catch2WithMain fmt::fmt spdlog::spdlog)

catch_discover_tests(
  LexerTests
  TEST_PREFIX
  "unittests."
  REPORTER
  XML
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "unittests."
  OUTPUT_SUFFIX
  .xml)
