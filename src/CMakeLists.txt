project(Network LANGUAGES CXX)

find_package(OpenBLAS REQUIRED)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME}
  ${HEADERS}
  ${SOURCES}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${OpenBLAS_LIB}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/SimpleAI
    ${OpenBLAS_INCLUDE_DIR}
)
