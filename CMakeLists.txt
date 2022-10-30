cmake_minimum_required(VERSION 3.10)

project(pathfinder)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(pathfinder src/main.cpp)

target_link_libraries(pathfinder sfml-graphics sfml-window sfml-system)
