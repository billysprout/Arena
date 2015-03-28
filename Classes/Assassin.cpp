#include "Assassin.hpp"
#include "Unit.hpp"
#include <string>
#include <array>

//constructor
Assassin::Assassin(int team, string name = "Assassin")
{
	_hp = 35, _armor = 12, _atkRange = 1, _atkType = 0, _atk = 18, _recovery = 1, _blkChance = 70;
	_chp = _hp, _carmor = _armor, _catkRange = _atkRange;
	_name = name;
	_class = "Assassin";
	_posX = 0;
	_posY = 0;
	_team = team;
	_movementRange = 4;
	_singleTarget = false;
}
string Assassin::toString()
{
	return "A";
}
void Assassin::target(Board *b)
{
	int k = b->_dimensions;
	//cycle through all units and attack them
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			Unit * temp = b->fetchUnitAt(i, j);
			if (canAttack(temp))
			{
				attack(temp);
			}
		}
	}
	_recoveringFor++;
}