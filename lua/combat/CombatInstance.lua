-- import damage instance and characters

-- player health values are not updating atm, need to fix

-- define local variables
local vars = {
  p1hp = 100, -- player health
  p2hp = 125,
  P1_MAX_HP = 100,
  P2_MAX_HP = 125,
  p1atk = 10, -- player attack damage
  p2atk = 5,
  p1skill = 20, -- player skill damage
  p2skill = 15,
  p1bag = 10, -- player bag heal
  p2bag = 20,
  p1flee = 5, -- player flee chance
  p2flee = 3,
  fled = false,
  current_player = 1 -- current player turn
}

-- deduct damage from health, if overkill return zero hp
function resolvedmg(hp, dmg)
  hp = hp - dmg
  if hp < 0 then
    hp = 0
  end
  return hp
end

-- add healing to health, if overheal return player's max hp
function resolveheal(hp, heal, player)
  hp = hp + heal
  if player == 1 then
    if hp > vars.P1_MAX_HP then
      hp = vars.P1_MAX_HP
    end
  else
    if hp > vars.P2_MAX_HP then
      hp = vars.P2_MAX_HP
    end
  end
  return hp
end

-- gen random number 1-100, if within flee chance, player flees, combat ends
function resolveflee(player)
  local flee_roll = math.random(1, 100)
  if player == 1 then
    vars.fled = (flee_roll <= vars.p1flee)
    return vars.fled
  else
    vars.fled = (flee_roll <= vars.p2flee)
    return vars.fled
  end
end


-- simulate pokemon style rpg combat menu
while (vars.current_player ~= 0)
do
  print("1. Attack")
  print("2. Skill")
  print("3. Bag")
  print("4. Flee")
  if vars.current_player == 1 then
    io.write("Player 1, select an action (1-4): ")
  elseif vars.current_player == 2 then
    io.write("Player 2, select an action (1-4): ")
  else
    print("Invalid player")
    -- error handling
  end
  player_selection = io.read("*n")

  -- resolve player selection
  -- attack instance
  if player_selection == 1 then
    print("You attack.")
    -- call damage instance with attack parameters
    if vars.current_player == 1 then
      vars.p2hp = resolvedmg(vars.p2hp, vars.p1atk)
      print("Player 1 attacks for ", vars.p1atk, "damage. Player 2 has ",
      vars.p2hp, "HP remaining.")
    else
      vars.p1hp = resolvedmg(vars.p1hp, vars.p2atk)
      print("Player 2 attacks for ", vars.p2atk, "damage. Player 1 has ",
      vars.p1hp, "HP remaining.")
    end

  -- skill instance
  elseif player_selection == 2 then
    print("You use a skill.")
    -- call damage instance with spell parameters
    if vars.current_player == 1 then
      vars.p2hp = resolvedmg(vars.p2hp, vars.p1skill)
      print("Player 1 uses a skill. It does ",
      vars.p1skill, "damage. Player 2 has ", vars.p2hp, "HP remaining.")
    else
      vars.p1hp = resolvedmg(vars.p1hp, vars.p2skill)
      print("Player 2 uses a skill. It does ",
      vars.p2skill, "damage. Player 1 has ", vars.p1hp, "HP remaining.")
    end

  -- bag instance
  elseif player_selection == 3 then
    print("You use an item from your bag.")
    -- call bag function
    if vars.current_player == 1 then
      vars.p1hp = resolveheal(vars.p1hp, vars.p1bag, vars.current_player)
      print("Player 1 uses a healing item. It heals ",
      vars.p1bag, "damage. Player 1 now has ", vars.p1hp, "HP remaining.")
    else
      vars.p2hp = resolveheal(vars.p2hp, vars.p2bag, vars.current_player)
      print("Player 2 uses a healing item. It heals ",
      vars.p2bag, "damage. Player 2 now has ", vars.p2hp, "HP remaining.")
    end

  -- flee instance
  elseif player_selection == 4 then
    print("You attempt to flee.")
    -- call flee function
    if vars.current_player == 1 then
      resolveflee(current_player)
      if not vars.fled then
        print("Player 1 failed to flee.")
      else
        print("Player 1 has fled the battle.")
        vars.current_player = 0
      end
    else
      resolveflee(current_player)
      if not vars.fled then
        print("Player 2 failed to flee.")
      else
        print("Player 2 has fled the battle.")
        vars.current_player = 0
      end
    end

  -- error case
  else
    print("Error Message")
    -- error handling
  end

  -- break out of loop if flee
  if vars.current_player == 0 then
    break
  end

  -- next player's turn if no one is dead
  if vars.p1hp <= 0 then
    print("Player 1 has died.")
    vars.current_player = 0
  elseif vars.p2hp <= 0 then
    print("Player 2 has died.")
    vars.current_player = 0
  else
    if vars.current_player == 1 then
      vars.current_player = 2
    else
      vars.current_player = 1
    end
  end
end
