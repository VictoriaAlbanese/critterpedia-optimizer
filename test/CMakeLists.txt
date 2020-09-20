################################################################################
#
# Programmer : Victoria Albanese
#   Filename : CMakeLists.txt
#
################################################################################

set(BINARY test_active_months)
add_executable(${BINARY} ${BINARY}.cpp)
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
target_link_libraries(${BINARY} PUBLIC ${GTEST_LIBRARIES} pthread)

set(BINARY test_active_hours)
add_executable(${BINARY} ${BINARY}.cpp)
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
target_link_libraries(${BINARY} PUBLIC ${GTEST_LIBRARIES} pthread)

################################################################################
