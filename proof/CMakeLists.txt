add_library(deemath_proof
  src/foo.cpp
)

add_library(deemath::proof ALIAS deemath_proof)

target_include_directories(deemath_proof
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(deemath_proof
    PUBLIC
        deemath::expression
)

if(BUILD_TESTING)
    add_executable(deemath_proof_tests tests/proof_first.cpp)

    target_link_libraries(deemath_proof_tests PRIVATE
        deemath::proof
        GTest::gtest_main
    )

    gtest_discover_tests(deemath_proof_tests)
endif()

if(MSVC)
  target_compile_options(deemath_proof PRIVATE /W4 /permissive-)
else()
  target_compile_options(deemath_proof PRIVATE -Wall -Wextra -Wpedantic)
endif()
