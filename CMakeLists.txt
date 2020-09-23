cmake_minimum_required(VERSION 3.10)
project(PulsarTest)

# Set the version number.
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)

#add_compile_options(-O0) # enable no optimization during development
add_compile_options(-Wall)

add_subdirectory(src)

