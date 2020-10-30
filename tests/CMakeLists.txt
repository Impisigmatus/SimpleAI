set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SimpleAI_tests LANGUAGES CXX)

find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/TestCases/*.cpp")

add_executable(${PROJECT_NAME}
  ${SOURCES}
  main.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${GTEST_LIBRARIES}
    Network
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE
    ${GTEST_INCLUDE_DIRS}
)
