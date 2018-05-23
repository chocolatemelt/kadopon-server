cmake_minimum_required (VERSION 3.0)
project (Simple-WebSocket-Server)

# ycm support
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# header include directories
include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/ext
	${PROJECT_SOURCE_DIR}/ext/ws
)

# build executables in bin/
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# g++ compiletime flags for C++14
if(NOT MSVC)
    add_compile_options(-std=c++14 -Wall -Wextra -Wsign-conversion)
else()
    add_compile_options(/W1)
endif()

add_library(simple-websocket-server INTERFACE)
target_include_directories(simple-websocket-server INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
find_package(Threads REQUIRED)
target_link_libraries(simple-websocket-server INTERFACE ${CMAKE_THREAD_LIBS_INIT})

# TODO 2020 when Debian Jessie LTS ends:
# Remove Boost system, thread, regex components; use Boost::<component> aliases; remove Boost target_include_directories
if(USE_STANDALONE_ASIO)
  target_compile_definitions(simple-websocket-server INTERFACE USE_STANDALONE_ASIO)
  include(CheckIncludeFileCXX)
  CHECK_INCLUDE_FILE_CXX(asio.hpp HAVE_ASIO)
  if(NOT HAVE_ASIO)
    message(FATAL_ERROR "Standalone Asio not found")
  endif()
else()
  find_package(Boost 1.54.0 COMPONENTS system thread coroutine context REQUIRED)
  target_link_libraries(simple-websocket-server INTERFACE ${Boost_LIBRARIES})
  target_include_directories(simple-websocket-server INTERFACE ${Boost_INCLUDE_DIR})
  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
    target_compile_definitions(simple-websocket-server INTERFACE USE_BOOST_REGEX)
    find_package(Boost 1.54.0 COMPONENTS regex REQUIRED)
    target_link_libraries(simple-websocket-server INTERFACE ${Boost_LIBRARIES})
    target_include_directories(simple-websocket-server INTERFACE ${Boost_INCLUDE_DIR})
  endif()
endif()
if(WIN32)
    target_link_libraries(simple-websocket-server INTERFACE ws2_32 wsock32)
endif()

# OSX has its own openssl implementation
if(APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
endif()
find_package(OpenSSL REQUIRED)
target_link_libraries(simple-websocket-server INTERFACE ${OPENSSL_LIBRARIES})
target_include_directories(simple-websocket-server INTERFACE ${OPENSSL_INCLUDE_DIR})

# server entrypoint
add_executable(kadopon src/main.cpp)
target_link_libraries(kadopon simple-websocket-server)
find_package(Boost 1.54.0 COMPONENTS system thread filesystem REQUIRED)
target_link_libraries(kadopon ${Boost_LIBRARIES})
target_include_directories(kadopon PRIVATE ${Boost_INCLUDE_DIR})

install(FILES server_ws.hpp client_ws.hpp server_wss.hpp client_wss.hpp crypto.hpp utility.hpp status_code.hpp DESTINATION include/simple-websocket-server)

# testing subfolder
enable_testing()
add_subdirectory(tests)
