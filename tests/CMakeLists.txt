# kadopon tests
set(TEST_SOURCES
  main.cpp

  character/create_character.cpp
  instance/instance_creation.cpp
  misc/position.cpp
  modifiers/increased_vs_more.cpp
  modifiers/item_applies_modifiers.cpp

  rng/rng.cpp
)

add_executable(kadotest ${TEST_SOURCES} ${KADOPON_SOURCES})
target_link_libraries(kadotest simple-websocket-server)
target_link_libraries(kadotest entityx)
target_link_libraries(kadotest fmt-header-only)
add_test(kadotest kadotest)
