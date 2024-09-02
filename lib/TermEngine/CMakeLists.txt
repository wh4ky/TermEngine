# Enable static library
option(ENABLE_STATIC "Enable static library" ON)

# Enable dynamic library
option(ENABLE_DYNAMIC "Enable dynamic library" ON)

if(ENABLE_STATIC)
    # Output of the static lib
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

    # Static library
    add_library(TermEngine-Static STATIC
    video/video.cpp
    video/color.cpp
    )

    # Static library properties
    set_target_properties(TermEngine-Static PROPERTIES
    OUTPUT_NAME stat${PROJECT_NAME}_${PROJECT_VERSION}
    )
endif()

if(ENABLE_DYNAMIC)
    # Dynamic library
    add_library(TermEngine-Dynamic SHARED
    video/video.cpp
    video/color.cpp
    )

    # Dynamic library properties
    set_target_properties(TermEngine-Dynamic PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out
    OUTPUT_NAME dyn${PROJECT_NAME}_${PROJECT_VERSION}
    )
endif()