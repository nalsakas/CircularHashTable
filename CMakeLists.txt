cmake_minimum_required(VERSION 3.10)
project(CircularHashTable)

add_executable(hashtable main.cpp)

list(APPEND CMAKE_PREFIX_PATH "C:/Catch2")
find_package(Catch2 REQUIRED)

add_executable(test test.cpp)
target_include_directories(test PUBLIC "${CMAKE_SOURCE_DIR}")
target_link_libraries(test PRIVATE Catch2::Catch2WithMain)