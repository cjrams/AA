cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/aaplus/*.h)
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/aaplus/*.cpp)

add_library(aaplus ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(aaplus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)

target_link_libraries(aaplus)
