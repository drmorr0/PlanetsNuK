
cmake_minimum_required (VERSION 2.8)
project (PlanetsNuK)

set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_FLAGS "-Wempty-body -Wall -Wextra ${CMAKE_CXX_FLAGS}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS_PROFILE "-g -O3 -DNDEBUG")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(Jsoncpp REQUIRED)
find_package(PkgConfig)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(CAIROMM REQUIRED cairomm-1.0)

include_directories(${Jsoncpp_INCLUD_DIRS} ${GTKMM_INCLUDE_DIRS} ${CAIROMM_INCLUDE_DIRS})
link_directories(${Jsoncpp_LIBRARY_DIRS} ${GTKMM_LIBRARY_DIRS} ${CAIROMM_LIBRARY_DIRS})

add_custom_target(red2green ALL
	COMMAND find ${CMAKE_BINARY_DIR} -name build.make
		-exec perl -pi -e "s/--red/--green/" "{}" "\;")

include_directories(include)
add_subdirectory(src)




