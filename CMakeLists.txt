cmake_minimum_required(VERSION 2.6)
project(HomeWork_TK3_StringArray)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB CPPS "*.cpp")
file(GLOB HPPS "*.hpp")

if(${UNIX})
	set(BUILD_OPTIONS -Wall -O2)
	add_definitions(${BUILD_OPTIONS})
endif()

add_executable(${PROJECT_NAME} ${CPPS} ${HPPS})
