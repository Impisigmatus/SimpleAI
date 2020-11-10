project(SimpleAI_tests LANGUAGES CXX)

find_package(GTest REQUIRED)

file(GLOB_RECURSE FIXATIONS "${CMAKE_CURRENT_SOURCE_DIR}/Fixations/*.*pp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/TestCases/*.cpp")

add_executable(${PROJECT_NAME}
  ${FIXATIONS}
  ${SOURCES}
  main.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${GTEST_LIBRARIES}
    Network
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Fixations
    ${GTEST_INCLUDE_DIRS}
)

# Копируем ассеты в папку билда
file(GLOB_RECURSE ASSETS "${CMAKE_CURRENT_SOURCE_DIR}/Assets/*")
file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR}/Assets)
add_definitions(-DASSETS_PATH=\"${CMAKE_BINARY_DIR}/Assets/\")
