cmake_minimum_required (VERSION 3.2) # If your CMake version is older, try modifying this line
project(BoyerMoore)

add_definitions(-std=c++1z -g)

########## Create libraries
add_library(RandomMatrixHashLib RandomMatrixHash.cpp)
add_library(BloomFilterLib BloomFilter.cpp RandomMatrixHash.cpp)

########## Link GoogleTest
include_directories($ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/gtest/mybuild)

########## Sanity Checks
add_executable(RandomMatrixHashSanityCheck RandomMatrixSanityCheck.cpp)
target_link_libraries(RandomMatrixHashSanityCheck gtest)
target_link_libraries(RandomMatrixHashSanityCheck pthread)
target_link_libraries(RandomMatrixHashSanityCheck RandomMatrixHashLib)

add_executable(BloomFilterSanityCheck BloomFilterSanityCheck.cpp)
target_link_libraries(BloomFilterSanityCheck gtest)
target_link_libraries(BloomFilterSanityCheck pthread)
target_link_libraries(BloomFilterSanityCheck RandomMatrixHashLib)
target_link_libraries(BloomFilterSanityCheck BloomFilterLib)
