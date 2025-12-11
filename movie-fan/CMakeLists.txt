cmake_minimum_required(VERSION 4.0)

project(movie-fan VERSION 1.0)

#Require C++23
set(CXX_STANDARD_REQUIRED ON) #Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets
set(CMAKE_CXX_SCAN_FOR_MODULES ON)


# Required fmt library
find_package(fmt CONFIG REQUIRED)

add_library(movie-fan_lib STATIC)
target_sources(movie-fan_lib PUBLIC
    FILE_SET modules TYPE CXX_MODULES FILES
    src/utilities.ixx
	src/Movies.ixx
)
target_compile_features(movie-fan_lib PUBLIC cxx_std_23)
target_link_libraries(movie-fan_lib PUBLIC fmt::fmt)

add_executable(movie-fan
    src/main.cpp
	src/classes/Movie.cpp
)

target_link_libraries(movie-fan PRIVATE movie-fan_lib fmt::fmt)
