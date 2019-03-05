# kadopon tests
set(TEST_SOURCES
  main.cpp
  character/character_factory.cpp
  misc/position.cpp
  random/random.cpp
  random/movement.cpp
)

add_executable(kadotest ${TEST_SOURCES} ${KADOPON_SOURCES})
target_link_libraries(kadotest simple-websocket-server)
target_link_libraries(kadotest fmt-header-only)
target_link_libraries(kadotest ${CZMQ_LIBRARY})
add_test(kadotest kadotest)
