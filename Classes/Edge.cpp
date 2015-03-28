#include "edge.hpp"
#include "Unit.hpp"

Edge::Edge()
{
	//assign default Knight statistics
	_hp = 50, _armor = 25, _atkRange = 1, _atkType = 0, _atk = 22, _recovery = 1, _blkChance = 80;
	_chp = _hp, _carmor = _armor, _catkRange = _atkRange;
	_name = "Edge";
	_class = "Unassigned";
	_posX = 0;
	_posY = 0;
	_team = -1;
	_movementRange = -1;
}
string Edge::toString()
{
	return " ";
}