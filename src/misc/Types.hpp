/**
 * Redefining some types within the source scope for consistency.
 */
#pragma once

#include <entt/entity/registry.hpp>

namespace Kadopon {
  using Registry = entt::DefaultRegistry;
  using Entity = Registry::entity_type;
}
