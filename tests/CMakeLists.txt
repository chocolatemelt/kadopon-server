# websockets Server tests
if(NOT MSVC)
  add_compile_options(-fno-access-control)

  add_executable(parse_test parse_test.cpp)
  target_link_libraries(parse_test simple-websocket-server)
  add_test(parse_test parse_test)
endif()

add_executable(io_test io_test.cpp)
target_link_libraries(io_test simple-websocket-server)
add_test(io_test io_test)

# kadopon tests
set(TEST_SOURCES
  main.cpp
  catch_sample.cpp
  crypto_test.cpp
  ex.cpp
  fmt.cpp
  rng/rng.cpp
  modifiers/increased_vs_more.cpp
)

add_executable(kadotest ${TEST_SOURCES} ${KADOPON_SOURCES})
target_link_libraries(kadotest simple-websocket-server)
target_link_libraries(kadotest entityx_shared)
target_link_libraries(kadotest fmt-header-only)
add_test(kadotest kadotest)
