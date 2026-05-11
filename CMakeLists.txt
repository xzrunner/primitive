cmake_minimum_required(VERSION 3.16)

project(primitive)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "include/primitive/Bitmap.inl"
)
source_group("" FILES ${no_group_source_files})

set(Headers
    "include/primitive/Bezier.h"
    "include/primitive/Bitmap.h"
    "include/primitive/Path.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "source/Bezier.cpp"
    "source/Path.cpp"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${no_group_source_files}
    ${Headers}
    ${Sources}
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
if(TARGET sm)
    target_link_libraries(${PROJECT_NAME} PRIVATE sm)
else()
    target_include_directories(${PROJECT_NAME} PRIVATE external/sm)
endif()
