#include "components/Life.hpp"
#include "Character.hpp"

void initialize(entityx::ptr<entityx::EntityManager> entities,
                entityx::ptr<entityx::EventManager> events) {
  entity_manager = entities;
  entity = entities->create();
  entity.assign<Life>(100);
}
