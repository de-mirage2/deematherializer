add_library(deemath_expression
  src/CompoundExpression.cpp
  src/Variable.cpp
)

add_library(deemath::expression ALIAS deemath_expression)

target_include_directories(deemath_expression PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

if(BUILD_TESTING)
  file( GLOB DEEMATH_EXPRESSION_TESTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
  add_executable(deemath_expression_tests "${DEEMATH_EXPRESSION_TESTS}")

  target_link_libraries(deemath_expression_tests PRIVATE
    deemath::expression
    GTest::gtest_main
  )

  gtest_discover_tests(deemath_expression_tests)
endif()

if(MSVC)
  target_compile_options(deemath_expression PRIVATE /W4 /permissive-)
else()
  target_compile_options(deemath_expression PRIVATE -Wall -Wextra -Wpedantic)
endif()
