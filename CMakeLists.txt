# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(TermEngine VERSION 0.1.0)

# C++ stuff
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Include dir
include_directories(${PROJECT_SOURCE_DIR}/include)

# Include CMakeLists.txt's from other directories
add_subdirectory(lib/TermEngine)