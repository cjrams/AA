cmake_minimum_required(VERSION 3.12)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(aaplus)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/aaplus/*.cpp)


list(REMOVE_ITEM SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/aaplus/AATest.cpp")

add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
)

target_link_libraries(${PROJECT_NAME})

enable_testing()

set (TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/aaplus/AATest.cpp")

add_executable(${PROJECT_NAME}-test ${TEST_SOURCES})

set_target_properties(${PROJECT_NAME}-test PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
)

target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})

add_test(NAME test COMMAND ${PROJECT_NAME}-test)
