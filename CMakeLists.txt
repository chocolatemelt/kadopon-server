cmake_minimum_required(VERSION 3.0)
project(kadopon-server)

# compilation targets
OPTION(BUILD_SERVER "Build kadopon server." ON)
OPTION(BUILD_TESTS "Build kadopon tests." ON)

# sanitize option
OPTION(SANITIZE "Add sanitize debug flags." ON)

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

# identify operating system
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(MACOSX TRUE)
endif()

# support for homebrew/macports
if(MACOSX)
  list(APPEND CMAKE_PREFIX_PATH /usr/local)
endif()

# ycm support
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# header include directories
include_directories(
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/ext
  ${PROJECT_SOURCE_DIR}/ext/spdlog
)

# sources
set(KADOPON_SOURCES
  ${PROJECT_SOURCE_DIR}/src/character/CharacterFactory.cpp

  ${PROJECT_SOURCE_DIR}/src/core/api/NetworkAPI.cpp
  ${PROJECT_SOURCE_DIR}/src/core/instance/GameInstance.cpp
  ${PROJECT_SOURCE_DIR}/src/core/server/KadoponMain.cpp

  ${PROJECT_SOURCE_DIR}/src/utilities/Random.cpp
)

# external libraries
add_subdirectory(ext/ws)
add_subdirectory(ext/fmt)

find_library(CZMQ_LIBRARY czmq)

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
if(SANITIZE)
  add_flag("-fsanitize=address,undefined")
endif()

IF(BUILD_SERVER)
  # server entrypoint
  add_executable(kadopon src/main.cpp ${KADOPON_SOURCES})
  target_link_libraries(kadopon simple-websocket-server)
  target_link_libraries(kadopon fmt-header-only)
  target_link_libraries(kadopon ${CZMQ_LIBRARY})

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
ENDIF(BUILD_SERVER)

IF(BUILD_TESTS)
  # testing subfolder
  enable_testing()
  add_subdirectory(tests)
ENDIF(BUILD_TESTS)

# output compilation flags
message(STATUS "Compilation flags: ${CMAKE_CXX_FLAGS}")
