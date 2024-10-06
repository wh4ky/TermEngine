# Options defined in root CMakeLists.txt

if(ENABLE_STATIC)
    # Output of the static lib
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

    # Static library
    add_library(TermEngine-Static STATIC
    video/video.cpp
    video/color.cpp
    )

    # Enable Lua bindings
    #[[
    if(ENABLE_LUA)
        target_sources(TermEngine-Static PRIVATE
        bindings/Lua.cpp 
        )
    endif()
    ]]
    
    # Static library properties
    set_target_properties(TermEngine-Static PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
    )
endif()

if(ENABLE_DYNAMIC)
    # Dynamic library
    add_library(TermEngine-Dynamic SHARED
    video/video.cpp
    video/color.cpp
    )

    # Enable Lua bindings
    #[[
    if(ENABLE_LUA)
        target_sources(TermEngine-Dynamic PRIVATE
        bindings/Lua.cpp 
        )
    endif()
    ]]

    # Dynamic library properties
    set_target_properties(TermEngine-Dynamic PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out
    OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
    )
endif()