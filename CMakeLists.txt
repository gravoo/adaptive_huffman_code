cmake_minimum_required(VERSION 3.10)
project(adaptive_huffman_code)

#  include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES "src/*.cpp")
add_executable(ahf main.cpp ${SOURCES})
target_include_directories(ahf PRIVATE ${CMAKE_SOURCE_DIR}/include)
