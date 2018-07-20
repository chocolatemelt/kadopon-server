#include "components/modifiers/Modifiers.hpp"
#include "utilities/ItemUtilities.hpp"

void ItemUtilities::equip_item(entityx::Entity character, Item item) {
  for(auto mod : item.modifiers->list) {
    if(mod->id() == "FLAT_LIFE") {
      // get character handle for flat life
      entityx::ComponentHandle<FlatLife> handle = character.component<FlatLife>();
      handle->value += mod->value;
    }
    else if(mod->id() == "MULTIPLICATIVE_LIFE") {
      entityx::ComponentHandle<MultiplicativeLife> handle = character.component<MultiplicativeLife>();
      for(auto v : mod->more) handle->more[v.first] += mod->more[v.first];
    }
  }
}
