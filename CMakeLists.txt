cmake_minimum_required(VERSION 3.27)
project(platformer)

set(CMAKE_CXX_STANDARD 17)

file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.40.6/CPM.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=3440292907e35353bf0761049d3680e9ed0031443c8ebeb9cbb6a421c4550ec1
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

CPMAddPackage(
        NAME flecs
        URL https://github.com/SanderMertens/flecs/archive/refs/tags/v4.0.4.zip
        VERSION 4.0.4
)
CPMAddPackage(
        NAME raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.zip
        VERSION 5.5
)

CPMAddPackage(
        NAME lua
        GIT_REPOSITORY https://github.com/lua/lua.git
        VERSION 5.3.5
        DOWNLOAD_ONLY YES
)
if (lua_ADDED)
    # lua has no CMake support, so we create our own target

    FILE(GLOB lua_sources ${lua_SOURCE_DIR}/*.c)
    list(REMOVE_ITEM lua_sources "${lua_SOURCE_DIR}/lua.c" "${lua_SOURCE_DIR}/luac.c")
    add_library(lua STATIC ${lua_sources})

    target_include_directories(lua
            PUBLIC
            $<BUILD_INTERFACE:${lua_SOURCE_DIR}>
    )
endif()

CPMAddPackage(
        NAME sol2
        URL https://github.com/ThePhD/sol2/archive/v3.3.0.zip
        VERSION 3.3.0
        DOWNLOAD_ONLY YES
)
if (sol2_ADDED)
    add_library(sol2 INTERFACE IMPORTED)
    target_include_directories(sol2 INTERFACE ${sol2_SOURCE_DIR}/include)
    target_link_libraries(sol2 INTERFACE lua)
endif()

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fsanitize=address -fsanitize=undefined")
endif()

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE flecs::flecs raylib sol2)

target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/res/")
