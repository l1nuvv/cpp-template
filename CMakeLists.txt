cmake_minimum_required(VERSION 4.2) # Синхронизируем с вашим CMakePresets.json

project(
  cpp_study_template
  VERSION 0.1.0
  LANGUAGES CXX
)


option(CPP_STUDY_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)


# Создаем исполняемый файл
add_executable(cpp-study-template
  src/main.cpp
)

target_compile_features(cpp-study-template PRIVATE cxx_std_20)

set_target_properties(cpp-study-template PROPERTIES
  CXX_EXTENSIONS NO
  CPP_STUDY_WARNINGS_AS_ERRORS ${CPP_STUDY_WARNINGS_AS_ERRORS}
)

if(MSVC)
  target_compile_options(cpp-study-template
    PRIVATE
      /W4          # Высокий уровень предупреждений
      /permissive- # Строгое соответствие стандарту
      /Zc:__cplusplus
      /utf-8       # Корректная кодировка
  )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(cpp-study-template
    PRIVATE
      -Wall
      -Wextra
      -Wpedantic
  )
endif()
