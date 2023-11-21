cmake_minimum_required(VERSION 3.25)
project(GravityTravellingSalesman)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)


add_executable(GravityTravellingSalesman src/main.cpp src/GravitySource.cpp include/GravitySource.h src/Traveller.cpp include/Traveller.h)

target_link_libraries(GravityTravellingSalesman sfml-graphics)