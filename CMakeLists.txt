cmake_minimum_required(VERSION 3.10)
project(adaptive_huffman_code)

set(SOURCES ${CMAKE_SOURCE_DIR}/src/Node.cpp ${CMAKE_SOURCE_DIR}/src/Transmiter.cpp ${CMAKE_SOURCE_DIR}/src/Tree.cpp)
add_executable(ahf main.cpp ${SOURCES})
target_include_directories(ahf PRIVATE ${CMAKE_SOURCE_DIR}/include)
