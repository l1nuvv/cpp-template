cmake_minimum_required(VERSION 4.2) # Синхронизируем с вашим CMakePresets.json

project(
  cpp_study_template
  VERSION 0.1.0
  LANGUAGES CXX
)

# Создаем исполняемый файл
add_executable(cpp-study-template
  src/main.cpp
)

target_compile_features(cpp-study-template PRIVATE cxx_std_20)

set_target_properties(cpp-study-template PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
  # Удобно для VS: группировка исходников
  VS_STARTUP_PROJECT cpp-study-template
)

target_include_directories(cpp-study-template
  PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

if(MSVC)
  target_compile_options(cpp-study-template
    PRIVATE
      /W4          # Высокий уровень предупреждений
      /permissive- # Строгое соответствие стандарту
      /Zc:__cplusplus
      /utf-8       # Корректная кодировка
      /EHsc        # Модель обработки исключений
      /WX          # Трактовать предупреждения как ошибки (рекомендуется для учебы)
  )
else()
  target_compile_options(cpp-study-template
    PRIVATE
      -Wall
      -Wextra
      -Wpedantic
      -Werror
  )
endif()
