cmake_minimum_required(VERSION 3.5)

project(SimpleAI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmakemodules)

add_subdirectory(src)

option(SAI_BUILD_TEST "Building test" OFF)
if (SAI_BUILD_TEST)
  add_subdirectory(tests)
endif (SAI_BUILD_TEST)

option(SAI_BUILD_EXAMPLE "Building example" OFF)
if (SAI_BUILD_EXAMPLE)
  add_subdirectory(example)
endif (SAI_BUILD_EXAMPLE)
