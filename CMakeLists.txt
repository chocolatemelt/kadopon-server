cmake_minimum_required(VERSION 3.0)
project(kadopon-server)

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type specified; falling back to `Debug`")
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(DEBUG FALSE)
set(RELEASE FALSE)
if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(DEBUG TRUE)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
	set(RELEASE TRUE)
endif()

# ycm support
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# header include directories
include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/src/rng

	${PROJECT_SOURCE_DIR}/ext
  ${PROJECT_SOURCE_DIR}/ext/entityx
)

# sources
set(KADOPON_SOURCES
  ${PROJECT_SOURCE_DIR}/src/entities/Character.cpp
  ${PROJECT_SOURCE_DIR}/src/rng/xorshift.cpp
  ${PROJECT_SOURCE_DIR}/src/systems/ScalingModifierSystem.cpp
)

# external libraries
add_subdirectory(ext/entityx)
add_subdirectory(ext/ws)
add_subdirectory(ext/fmt)

# build executables in bin/
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# g++ compiletime flags for C++14
if(NOT MSVC)
    add_compile_options(
      -std=c++14
      -Wall
      -Wextra
      -Wno-sign-compare
      -Wno-unused-parameter
    )
    
    # google sanitize flags for debugging
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined")
else()
    add_compile_options(/W1)
endif()

# server entrypoint
add_executable(kadopon src/main.cpp ${KADOPON_SOURCES})
target_link_libraries(kadopon simple-websocket-server)
target_link_libraries(kadopon entityx_shared)
target_link_libraries(kadopon fmt-header-only)
find_package(Boost 1.54.0 COMPONENTS system thread filesystem REQUIRED)
target_link_libraries(kadopon ${Boost_LIBRARIES})
target_include_directories(kadopon PRIVATE ${Boost_INCLUDE_DIR})

# testing subfolder
enable_testing()
add_subdirectory(tests)
