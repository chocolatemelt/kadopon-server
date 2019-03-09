-- import damage instance and characters

-- player health values are not updating atm, need to fix

-- define local variables
local p1hp, p2hp = 100, 125 -- player health
local p1atk, p2atk = 10, 5 -- player attack damage
local p1skill, p2skill = 20, 15 -- player skill damage
local p1bag, p2bag = 10, 20 -- player bag heal
local p1flee, p2flee = 5, 3 -- player flee chance
local currentplayer = 1 -- current player turn

-- deduct damage from health, if overkill return zero hp
function resolvedmg(hp, dmg)
  hp = hp - dmg
  if hp < 0 then
    hp = 0
  end
  return hp
end

-- simulate pokemon style rpg combat menu
while (currentplayer ~= 0)
do
  print("1. Attack")
  print("2. Skill")
  print("3. Bag")
  print("4. Flee")
  if currentplayer == 1 then
    io.write("Player 1, select an action (1-4): ")
  elseif currentplayer == 2 then
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
    if currentplayer == 1 then
      resolvedmg(p2hp, p1atk)
      print("Player 1 attacks for ", p1atk, "damage. Player 2 has ", p2hp, "HP remaining.")
    else
      resolvedmg(p1hp, p2atk)
      print("Player 2 attacks for ", p2atk, "damage. Player 1 has ", p1hp, "HP remaining.")
    end

  -- skill instance
  elseif player_selection == 2 then
    print("You use a skill.")
    -- call damage instance with spell parameters
    if currentplayer == 1 then
      resolvedmg(p2hp, p1skill)
      print("Player 1 uses a skill. It does ", p1atk, "damage. Player 2 has ", p2hp, "HP remaining.")
    else
      resolvedmg(p1hp, p2skill)
      print("Player 2 uses a skill. It does ", p2atk, "damage. Player 1 has ", p1hp, "HP remaining.")
    end

  -- bag instance
  elseif player_selection == 3 then
    print("You use an item from your bag.")
    -- call bag function

  -- flee instance
  elseif player_selection == 4 then
    print("You attempt to flee.")
    -- call flee function
  else
    print("Error Message")
    -- error handling
  end

  -- next player's turn if no one is dead
  if p1hp <= 0 then
    currentplayer = 0
  elseif p2hp <= 0 then
    currentplayer = 0
  else
    if currentplayer == 1 then
      currentplayer = 2
    else
      currentplayer = 1
    end
  end
end
