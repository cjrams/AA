cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/aaplus/*.h)
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/aaplus/*.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/aaplus/AATest.cpp")

list(REMOVE_ITEM SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/aaplus/AATest.cpp")

add_library(aaplus ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(aaplus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)
target_link_libraries(aaplus)

#enable_testing()

add_executable(test ${TEST_SOURCES} )
target_link_libraries(test aaplus)
#add_test(test test)
