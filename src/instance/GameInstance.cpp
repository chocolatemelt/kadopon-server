#include "components/attributes/Attributes.hpp"
#include "components/modifiers/Modifiers.hpp"
#include "entityx/deps/Dependencies.h"
#include "instance/GameInstance.hpp"
#include "systems/ScalingModifierSystem.hpp"

GameInstance::GameInstance() : events(), entities(events), systems(entities, events) {
  // set up component dependencies
  systems.add<entityx::deps::Dependency<Life, FlatLife, AdditiveLife, MultiplicativeLife> >();

  // set up systems
  systems.add<ScalingModifierSystem>();

  // configure
  systems.configure();
}
