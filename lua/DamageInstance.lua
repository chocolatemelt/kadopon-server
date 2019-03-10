-------Damage Instance-------

--Damage instance will take in an ability with attributes, and a character
--then will inflict the character with the abilities effects... poison, spell_damage, 

--for now... send in the damage and type that will be inflicted onto the character
local DamageInstance =  {}

function DamageInstance.Damage(damageT, character_name)
	local character = require(character_name)
	--inflict damage on character C
	local attack_dmg = damageT[1]
	local attack_type = damageT[2]

	local reduced_damage = attack_dmg - resistance(attack_type,character)

	character.hp = character.hp - reduced_damage

end
	


function resistance(type,character)
	local resist = -1
	if type == 'physical' then
		resist = character.armour
	elseif type == 'fire' then
		resist = character.fres
	elseif type == 'cold' then
		resist = character.cres
	elseif type == 'light' then
		resist = character.lres
	end

	assert(resist ~= -1)
	return resist
end

return DamageInstance


