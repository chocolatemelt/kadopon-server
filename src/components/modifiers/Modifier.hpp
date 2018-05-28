/**
 * The basic modifier component. Modifiers are a generic brand of components that can be attached to
 * items or characters. Most modifiers are scaling modifiers, which directly affect an Attribute;
 * other modifiers simply tag along as another component to be assigned to a Character, affecting
 * various aspects of gameplay.
 */
#pragma once

#include "entityx/entityx.h"

struct Modifier : entityx::Component<Modifier> {};
