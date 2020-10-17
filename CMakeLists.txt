cmake_minimum_required(VERSION 3.16.0)
enable_testing()

include_directories(external/pistache)
include_directories(external/json/single_include/nlohmann)

project(vscode-template)
add_executable(main main.cpp)
target_link_libraries(main pistache_static)

add_subdirectory(test)
add_subdirectory(external)
add_subdirectory(pistache_api_client)