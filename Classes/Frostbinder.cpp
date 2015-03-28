#include "Frostbinder.hpp"

//constructor
Frostbinder::Frostbinder(int team, string name = "Frostbinder")
{
	_hp = 60, _armor = 0, _atkRange = 4, _atkType = 0, _atk = 0, _recovery = 1, _blkChance = 0;
	_chp = _hp, _carmor = _armor, _catkRange = _atkRange;
	_name = name;
	_class = "Frostbinder";
	_posX = 0;
	_posY = 0;
	_team = team;
	_movementRange = 2;
	_singleTarget = true;

}
string Frostbinder::toString()
{
	return "/";
}

void Frostbinder::attack(Unit * unit)
{
	if (canAttack(unit))
	{
		unit->_isParalyzed = true;
		_isFocused = true;
		_focusedOn = unit;
		unit->_focusedBy = this;
		this->_focusedOn = unit;
	}
}