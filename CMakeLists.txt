# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Whacky-Engine VERSION 0.0.0)

# C++ stuff
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED false)

# Include dir
include_directories(${PROJECT_SOURCE_DIR}/include)

# Output of the static lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

# Static library
add_library(Whacky-Engine-Static STATIC
    src/Whacky-Engine/video.cpp
    src/Whacky-Engine/color.cpp
)

set_target_properties(Whacky-Engine-Static PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
)

# Dynamic library
add_library(Whacky-Engine-Dynamic SHARED
    src/Whacky-Engine/video.cpp
    src/Whacky-Engine/color.cpp
)

set_target_properties(Whacky-Engine-Dynamic PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out
    OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
)