cmake_minimum_required(VERSION 3.0)
project(kadopon-server)

# build flags
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type specified; falling back to DEBUG")
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
  ${PROJECT_SOURCE_DIR}/src/rng/xorshift.cpp
  ${PROJECT_SOURCE_DIR}/src/utilities/ModifierUtilities.cpp
  ${PROJECT_SOURCE_DIR}/src/systems/ScalingModifierSystem.cpp
)

# external libraries
add_subdirectory(ext/entityx)
add_subdirectory(ext/ws)
add_subdirectory(ext/fmt)

# build executables in bin/
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# build-specific compilation flags
set(COMMON_FLAGS
  -std=c++14
  -Wall
  -Wextra
  -Wno-sign-compare
  -Wno-unused-parameter
)
set(DEBUG_FLAGS
  -ggdb
  -fsanitize=address,undefined
  --coverage
)
set(RELEASE_FLAGS
  -O3
  -fomit-frame-pointer
  -ffunction-sections
  -fdata-sections
  -fno-unwind-tables
  -fno-asynchronous-unwind-tables
  -fno-math-errno
  -fno-unroll-loops
  -fmerge-all-constants
  -fno-ident
  -ffast-math
)

function(add_flag FLAG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAG}" PARENT_SCOPE)
endfunction()
foreach(FLAG ${COMMON_FLAGS})
  add_flag(${FLAG})
endforeach()
if(${DEBUG})
  foreach(FLAG ${DEBUG_FLAGS})
  add_flag(${FLAG})
  endforeach()
endif()
if(${RELEASE})
  foreach(FLAG ${RELEASE_FLAGS})
  add_flag(${FLAG})
  endforeach()
endif()

# server entrypoint
add_executable(kadopon src/main.cpp ${KADOPON_SOURCES})
target_link_libraries(kadopon simple-websocket-server)
target_link_libraries(kadopon entityx)
target_link_libraries(kadopon fmt-header-only)

# boost
find_package(Boost 1.54.0 COMPONENTS system thread filesystem REQUIRED)
target_link_libraries(kadopon ${Boost_LIBRARIES})
target_include_directories(kadopon PRIVATE ${Boost_INCLUDE_DIR})

# openssl
if(APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
endif()
find_package(OpenSSL REQUIRED)
target_link_libraries(kadopon ${OPENSSL_LIBRARIES})
target_include_directories(kadopon PRIVATE ${OPENSSL_INCLUDE_DIR})

# testing subfolder
enable_testing()
add_subdirectory(tests)
message(STATUS "compilation flags: ${CMAKE_CXX_FLAGS}")
