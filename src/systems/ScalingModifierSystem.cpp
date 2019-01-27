#include "systems/ScalingModifierSystem.hpp"

void ScalingModifierSystem::update(entityx::EntityManager &em,
                                   entityx::EventManager &es,
                                   double dt) {
  for(auto m : em.entities_with_components<Life, AdditiveLife, FlatLife, MultiplicativeLife>()) {
    // grab component handles
    entityx::ComponentHandle<Life> base;
    entityx::ComponentHandle<AdditiveLife> add;
    entityx::ComponentHandle<FlatLife> flat;
    entityx::ComponentHandle<MultiplicativeLife> multi;
    m.unpack<Life>(base);
    m.unpack<AdditiveLife>(add);
    m.unpack<FlatLife>(flat);
    m.unpack<MultiplicativeLife>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<Mana, AdditiveMana, FlatMana, MultiplicativeMana>()) {
    // grab component handles
    entityx::ComponentHandle<Mana> base;
    entityx::ComponentHandle<AdditiveMana> add;
    entityx::ComponentHandle<FlatMana> flat;
    entityx::ComponentHandle<MultiplicativeMana> multi;
    m.unpack<Mana>(base);
    m.unpack<AdditiveMana>(add);
    m.unpack<FlatMana>(flat);
    m.unpack<MultiplicativeMana>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }
/*
  for(auto m : em.entities_with_components<LifeRegen, AdditiveLifeRegen, FlatLifeRegen, MultiplicativeLifeRegen>()) {
    // grab component handles
    entityx::ComponentHandle<LifeRegen> base;
    entityx::ComponentHandle<AdditiveLifeRegen> add;
    entityx::ComponentHandle<FlatLifeRegen> flat;
    entityx::ComponentHandle<MultiplicativeLifeRegen> multi;
    m.unpack<LifeRegen>(base);
    m.unpack<AdditiveLifeRegen>(add);
    m.unpack<FlatLifeRegen>(flat);
    m.unpack<MultiplicativeLifeRegen>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<ManaRegen, AdditiveManaRegen, FlatManaRegen, MultiplicativeManaRegen>()) {
    // grab component handles
    entityx::ComponentHandle<ManaRegen> base;
    entityx::ComponentHandle<AdditiveManaRegen> add;
    entityx::ComponentHandle<FlatManaRegen> flat;
    entityx::ComponentHandle<MultiplicativeManaRegen> multi;
    m.unpack<ManaRegen>(base);
    m.unpack<AdditiveManaRegen>(add);
    m.unpack<FlatManaRegen>(flat);
    m.unpack<MultiplicativeManaRegen>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }
*/
  for(auto m : em.entities_with_components<Armour, AdditiveArmour, FlatArmour, MultiplicativeArmour>()) {
    // grab component handles
    entityx::ComponentHandle<Armour> base;
    entityx::ComponentHandle<AdditiveArmour> add;
    entityx::ComponentHandle<FlatArmour> flat;
    entityx::ComponentHandle<MultiplicativeArmour> multi;
    m.unpack<Armour>(base);
    m.unpack<AdditiveArmour>(add);
    m.unpack<FlatArmour>(flat);
    m.unpack<MultiplicativeArmour>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<Evasion, AdditiveEvasion, FlatEvasion, MultiplicativeEvasion>()) {
    // grab component handles
    entityx::ComponentHandle<Evasion> base;
    entityx::ComponentHandle<AdditiveEvasion> add;
    entityx::ComponentHandle<FlatEvasion> flat;
    entityx::ComponentHandle<MultiplicativeEvasion> multi;
    m.unpack<Evasion>(base);
    m.unpack<AdditiveEvasion>(add);
    m.unpack<FlatEvasion>(flat);
    m.unpack<MultiplicativeEvasion>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }
/*
  for(auto m : em.entities_with_components<Accuracy, AdditiveAccuracy, FlatAccuracy, MultiplicativeAccuracy>()) {
    // grab component handles
    entityx::ComponentHandle<Accuracy> base;
    entityx::ComponentHandle<AdditiveAccuracy> add;
    entityx::ComponentHandle<FlatAccuracy> flat;
    entityx::ComponentHandle<MultiplicativeAccuracy> multi;
    m.unpack<Accuracy>(base);
    m.unpack<AdditiveAccuracy>(add);
    m.unpack<FlatAccuracy>(flat);
    m.unpack<MultiplicativeAccuracy>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<Block, AdditiveBlock, FlatBlock, MultiplicativeBlock>()) {
    // grab component handles
    entityx::ComponentHandle<Block> base;
    entityx::ComponentHandle<AdditiveBlock> add;
    entityx::ComponentHandle<FlatBlock> flat;
    entityx::ComponentHandle<MultiplicativeBlock> multi;
    m.unpack<Block>(base);
    m.unpack<AdditiveBlock>(add);
    m.unpack<FlatBlock>(flat);
    m.unpack<MultiplicativeBlock>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<Dodge, AdditiveDodge, FlatDodge, MultiplicativeDodge>()) {
    // grab component handles
    entityx::ComponentHandle<Dodge> base;
    entityx::ComponentHandle<AdditiveDodge> add;
    entityx::ComponentHandle<FlatDodge> flat;
    entityx::ComponentHandle<MultiplicativeDodge> multi;
    m.unpack<Dodge>(base);
    m.unpack<AdditiveDodge>(add);
    m.unpack<FlatDodge>(flat);
    m.unpack<MultiplicativeDodge>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<FireRes, AdditiveFireRes, FlatFireRes, MultiplicativeFireRes>()) {
    // grab component handles
    entityx::ComponentHandle<FireRes> base;
    entityx::ComponentHandle<AdditiveFireRes> add;
    entityx::ComponentHandle<FlatFireRes> flat;
    entityx::ComponentHandle<MultiplicativeFireRes> multi;
    m.unpack<FireRes>(base);
    m.unpack<AdditiveFireRes>(add);
    m.unpack<FlatFireRes>(flat);
    m.unpack<MultiplicativeFireRes>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<ColdRes, AdditiveColdRes, FlatColdRes, MultiplicativeColdRes>()) {
    // grab component handles
    entityx::ComponentHandle<ColdRes> base;
    entityx::ComponentHandle<AdditiveColdRes> add;
    entityx::ComponentHandle<FlatColdRes> flat;
    entityx::ComponentHandle<MultiplicativeColdRes> multi;
    m.unpack<ColdRes>(base);
    m.unpack<AdditiveColdRes>(add);
    m.unpack<FlatColdRes>(flat);
    m.unpack<MultiplicativeColdRes>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<LightningRes, AdditiveLightningRes, FlatLightningRes, MultiplicativeLightningRes>()) {
    // grab component handles
    entityx::ComponentHandle<LightningRes> base;
    entityx::ComponentHandle<AdditiveLightningRes> add;
    entityx::ComponentHandle<FlatLightningRes> flat;
    entityx::ComponentHandle<MultiplicativeLightningRes> multi;
    m.unpack<LightningRes>(base);
    m.unpack<AdditiveLightningRes>(add);
    m.unpack<FlatLightningRes>(flat);
    m.unpack<MultiplicativeLightningRes>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<CritChance, AdditiveCritChance, FlatCritChance, MultiplicativeCritChance>()) {
    // grab component handles
    entityx::ComponentHandle<CritChance> base;
    entityx::ComponentHandle<AdditiveCritChance> add;
    entityx::ComponentHandle<FlatCritChance> flat;
    entityx::ComponentHandle<MultiplicativeCritChance> multi;
    m.unpack<CritChance>(base);
    m.unpack<AdditiveCritChance>(add);
    m.unpack<FlatCritChance>(flat);
    m.unpack<MultiplicativeCritChance>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }

  for(auto m : em.entities_with_components<CritMulti, AdditiveCritMulti, FlatCritMulti, MultiplicativeCritMulti>()) {
    // grab component handles
    entityx::ComponentHandle<CritMulti> base;
    entityx::ComponentHandle<AdditiveCritMulti> add;
    entityx::ComponentHandle<FlatCritMulti> flat;
    entityx::ComponentHandle<MultiplicativeCritMulti> multi;
    m.unpack<CritMulti>(base);
    m.unpack<AdditiveCritMulti>(add);
    m.unpack<FlatCritMulti>(flat);
    m.unpack<MultiplicativeCritMulti>(multi);

    ModifierUtilities::update_total(base, add, flat, multi);
  }*/
}
