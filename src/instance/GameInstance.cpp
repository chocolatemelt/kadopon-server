#include "components/attributes/Attributes.hpp"
#include "components/modifiers/Modifiers.hpp"
#include "entityx/deps/Dependencies.h"
#include "instance/GameInstance.hpp"
#include "systems/ScalingModifierSystem.hpp"

GameInstance::GameInstance() : events(), entities(events), systems(entities, events) {
  // set up component dependencies
  systems.add<entityx::deps::Dependency<Life, FlatLife, AdditiveLife, MultiplicativeLife> >();
  systems.add<entityx::deps::Dependency<Mana, FlatMana, AdditiveMana, MultiplicativeMana> >();

  // set up systems
  systems.add<ScalingModifierSystem>();

  // configure
  systems.configure();
}

void GameInstance::update_modifiers() {
  systems.update<ScalingModifierSystem>(0.0);
}

void GameInstance::update_modifiers(double dt) {
  systems.update<ScalingModifierSystem>(dt);
}
