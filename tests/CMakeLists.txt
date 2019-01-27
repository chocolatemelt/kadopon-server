# kadopon tests
set(TEST_SOURCES
  main.cpp

  boardgame/boardgame.cpp
  character/create_character.cpp
  instance/instance_creation.cpp
  misc/position.cpp
  modifiers/increased_vs_more.cpp
  modifiers/item_applies_modifiers.cpp

  random/random.cpp
  random/movement.cpp
)

add_executable(kadotest ${TEST_SOURCES} ${KADOPON_SOURCES})
target_link_libraries(kadotest simple-websocket-server)
target_link_libraries(kadotest entityx)
target_link_libraries(kadotest fmt-header-only)
add_test(kadotest kadotest)
