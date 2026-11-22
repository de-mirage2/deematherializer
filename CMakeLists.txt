cmake_minimum_required(VERSION 3.23)

project(Deematherializer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

if(BUILD_TESTING)
  enable_testing()
  include(FetchContent)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.18.0
  )

  if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  endif()

  FetchContent_MakeAvailable(googletest)
  include(GoogleTest)
endif()

add_subdirectory(expression)
add_subdirectory(proof)

# # Build the application from main.cpp and impl. files
# add_executable(Deematherializer main.cpp)
