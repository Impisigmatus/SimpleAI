project(SimpleAI_tests LANGUAGES CXX)

find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

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
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${GTEST_INCLUDE_DIRS}
)
