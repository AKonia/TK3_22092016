project(HomeWork_TK3_StringArray)
cmake_minimum_required(VERSION 2.6)
set(SOURCES core.cpp StringArray.hpp)

if(${UNIX})
	set(BUILD_OPTIONS -Wall -O2)
	add_definitions(${BUILD_OPTIONS})
	message(STATUS "Building on Linux")
elseif(${WIN32})
	message(STATUS "Building on Windows")
endif()

if(DEFINED DEBUG)
	message("Are you sure you wanna DEBUG ?")
endif()

add_executable(${PROJECT_NAME} ${SOURCES})
