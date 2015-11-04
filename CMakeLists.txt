project(dfs-graph)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

