################################################################################
#
# Programmer : Victoria Albanese
#   Filename : CMakeLists.txt
#
################################################################################

cmake_minimum_required(VERSION 3.10)          
project(critterpedia)                        

find_package(GTest REQUIRED)                

include_directories(${GTEST_INCLUDE_DIRS})      
include_directories(src)                    

add_subdirectory(src)                       
add_subdirectory(test)                        

################################################################################
