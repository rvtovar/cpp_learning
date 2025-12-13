cmake_minimum_required(VERSION 4.0)

project(overloading VERSION 1.0)

#Require C++23
set(CXX_STANDARD_REQUIRED ON) #Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets
set(CMAKE_CXX_SCAN_FOR_MODULES ON)


find_package(fmt CONFIG REQUIRED)


add_library(overloading_lib STATIC)
target_sources(overloading_lib PUBLIC
    FILE_SET modules TYPE CXX_MODULES FILES
    src/utilities.ixx
)
target_compile_features(overloading_lib PUBLIC cxx_std_23)
target_link_libraries(overloading_lib PUBLIC fmt::fmt)

add_executable(overloading
    src/main.cpp
	src/classes/MyString.cpp
)

target_link_libraries(overloading PRIVATE overloading_lib fmt::fmt)
