set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SimpleAI_tests LANGUAGES CXX)

find_package(GTest REQUIRED)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME}
  ${HEADERS}
  ${SOURCES}
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
