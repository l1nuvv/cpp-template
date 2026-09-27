cmake_minimum_required(VERSION 4.2)

project(
  cpp_study_template
  VERSION 0.1.0
  LANGUAGES CXX
)

option(
  CPP_STUDY_WARNINGS_AS_ERRORS
  "Treat compiler warnings as errors"
  OFF
)

add_executable(cpp-study-template
  src/main.cpp
)

target_compile_features(cpp-study-template
  PRIVATE
    cxx_std_20
)

set_target_properties(cpp-study-template PROPERTIES
  CXX_EXTENSIONS OFF
  COMPILE_WARNING_AS_ERROR ${CPP_STUDY_WARNINGS_AS_ERRORS}
)

if(MSVC)
  target_compile_options(cpp-study-template
    PRIVATE
      /W4
      /permissive-
      /Zc:__cplusplus
      /utf-8
  )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(cpp-study-template
    PRIVATE
      -Wall
      -Wextra
      -Wpedantic
  )
endif()
