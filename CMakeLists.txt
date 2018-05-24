cmake_minimum_required (VERSION 3.0)
project (kadopon-server)

# ycm support
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# header include directories
include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/ext
  ${PROJECT_SOURCE_DIR}/ext/entityx
)

add_subdirectory(ext/entityx)
add_subdirectory(ext/ws)
add_subdirectory(ext/fmt)

# build executables in bin/
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# g++ compiletime flags for C++14
if(NOT MSVC)
    add_compile_options(-std=c++14 -Wall -Wextra -Wsign-conversion)
else()
    add_compile_options(/W1)
endif()

# server entrypoint
add_executable(kadopon src/main.cpp)
target_link_libraries(kadopon simple-websocket-server)
target_link_libraries(kadopon entityx_shared)
target_link_libraries(kadopon fmt-header-only)
find_package(Boost 1.54.0 COMPONENTS system thread filesystem REQUIRED)
target_link_libraries(kadopon ${Boost_LIBRARIES})
target_include_directories(kadopon PRIVATE ${Boost_INCLUDE_DIR})

# testing subfolder
enable_testing()
add_subdirectory(tests)
