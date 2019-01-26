/**
 * Class for combat instance. Combat instances involve two characters and their actions.
 */
#pragma once

class CombatInstance {
public:
    //the two members of the combat instance
    Chara c1, c2;

    int turn;
};