#include "knight.hpp"

//constructor
Knight::Knight(int team, string name="Knight")
{
	//assign default Knight statistics
	 _hp = 50, _armor = 25, _atkRange = 1, _atkType = 0, _atk = 22, _recovery = 1, _blkChance = 80;
	 _chp = _hp, _carmor = _armor, _catkRange = _atkRange;
	_name = name;
	_class = "Warrior";
	_posX = 0;
	_posY = 0;
	_team = team;
	_movementRange = 3;
	_singleTarget = true;
}
string Knight::toString()
{
	return "X";
}