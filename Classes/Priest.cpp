#include "Priest.hpp"
#include "Unit.hpp"
#include <string>
#include <array>

//constructor
Priest::Priest(int team, string name = "Priest")
{
	_hp = 24, _armor = 0, _atkRange = 100, _atkType = 0, _atk = 0, _recovery = 5, _blkChance = 0;
	_chp = _hp, _carmor = _armor, _catkRange = _atkRange;
	_name = name;
	_class = "Priest";
	_posX = 0;
	_posY = 0;
	_team = team;
	_movementRange = 3;
	_singleTarget = false;
}
string Priest::toString()
{
	return "O";
}
void Priest::target(Board *b)
{
	int k = b->_dimensions;
	//cycle through all units and heal them if their team is his
	//if (_recoveringFor != 0)
	{
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				Unit * temp = b->fetchUnitAt(i, j);
				if (temp->_team == _team && !temp->_isProtected && temp->_chp != temp->_hp)
				{
					int totalHeal = 15;
					//overheal checker
					if (temp->_chp + totalHeal > temp->_hp)
					{
						totalHeal = temp->_hp - temp->_chp;
					}
					temp->_chp += totalHeal;
					cout << "Healing " << temp->_name << " for " << totalHeal << " HP.\n";
					cout << ">ATTACK: Heal Complete.\n";

				}
			}
		}
		_recoveringFor += 4;
	}
/*	else
		cout << ">ATTACK: " << _name << " is still recovering.\n";
	_recoveringFor += (_recovery - 1);
	*/
}