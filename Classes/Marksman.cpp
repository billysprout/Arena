#include "Marksman.hpp"

//constructor
Marksman::Marksman(int team, string name="Marksman")
{
	_hp = 40, _armor = 8, _atkRange = 6, _atkType = 0, _atk = 18, _recovery = 1, _blkChance = 40;
	_chp = _hp, _carmor = _armor, _catkRange = _atkRange;
	_name = name;
	_class = "Marksman";
	_posX = 0;
	_posY = 0;
	_team = team;
	_movementRange = 4;
	_singleTarget = true;
}
string Marksman::toString()
{
	return ">";
}