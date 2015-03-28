#include "Unit.hpp"
#include "Board.hpp"
class Unit;
Unit::Unit(){

	_hp = 1;
	_armor = 0;
	_atkRange = 0;
	_atkType = 0;
	_atk = 0;
	_recovery = 0;
	_blkChance = 0;
	_movementRange = 4;
	_chp = 1;
	_carmor = 0;
	_catkRange = 0;
	_team = -1;
	_posX = 0;
	_posY = 0;
	_isParalyzed = false;
	_isProtected = false;
	_isArtifact = false;
	_isFocused = false;
	_singleTarget = true;
	_recoveringFor = 0;
};

//combat & traversal	
bool Unit::canMove(int x, int y)
{
	int ax, ay, tx, ty, ar;
	ax = getPosition("x");
	ay = getPosition("y");
	tx = x;
	ty = y;
	ar = _movementRange;

	bool inRange = (abs(ty - ay) + abs(tx - ax)) <= ar;
	if (!_isParalyzed && inRange && _recoveringFor<=0)
		return true;
	else
		return false;
}
void Unit::attack(Board b){}
void Unit::attack(Unit * target)
{
	//sends attack damage to target if they're in range
	if (canAttack(target))
	{
		target->damage(this);
		if (_singleTarget==true)
			_recoveringFor += (_recovery);
	}
}
void Unit::damage(Unit * attacker)
{
	//inflicts attacker's attack damage on this-> if not blocked
	int damage_dealt = attacker->_atk;
	int damage_received = double(damage_dealt)*(1 - (double(_carmor) / 100));
	cout << "Sending " << damage_dealt << " damage...\n";
	cout << "Received " << damage_received << " damage.\n";
	if (!attacker->block(2, 0))
	{
		setCHP(_chp - damage_received);
		_isFocused = false;
	}
}
bool Unit::block(int side, int atkType)
{
	int rng = rand() % 100 + 1;
	srand(time(NULL));
	rng = rand() % 100 + 1;
	bool result;
	cout << "Rolled " << rng << " out of 100.\n";
	// if atk isnt magic type and is from a side other than the back
	if (atkType != 1 && side != 3)
	{
		if (side == 0)
			result = rng > _blkChance;
		else
			result = rng > (_blkChance / 2);
	}
	else
		result = true;
	if (result)
	{
		cout << "Attack was successful.\n";
		return false;
	}
	else
	{
		cout << "Attack was blocked!\n";
		return true;
	}
}
void Unit::target(Board * b){
	cout << "This unit can't heal idiot\n";
}
bool Unit::canAttack(Unit * target)
{
	int ax, ay, tx, ty, ar;
	ax = getPosition("x");
	ay = getPosition("y");
	tx = target->getPosition("x");
	ty = target->getPosition("y");
	ar = getCAtkRange();

	cout << _name << " (" << ax << "," << ay << ") attacking " << target->_name << " (" << tx << "," << ty << "), ";

	bool inRange = (abs(tx - ax) + abs(ty - ay)) <= ar;

	//check if is blank or paralyzed, and if target is immune
	if (_recoveringFor > 0)
	{
		cout << "but he's still recovering.\n";
		return false;
	}
	else if (!target->_isProtected)
	{
		if (!_isParalyzed)
		{
			if (_team == target->_team)
			{
				cout << "but they're teammates!\n";
				return false;
			}
			else if (inRange)
			{
				cout << "from within range.\n";
				return true;
			}
			else
			{
				cout << "from out of range.\n";
				return false;
			}
		}
		else
		{
			cout << "but attacker is paralyzed.\n";
			return false;
		}
	}
//	else
	{
		cout << "Target is immune.\n";
		return false;
	}
}

//printers
void Unit::printAll()
{
	//scale hp % to x/10
	int percentage = double(_chp) / _hp * 10;
	// print name
	cout << "---------------------------------------------------------\n"
		 << _name << " the " << _class << endl;
	//print out current HP
	cout << "<[";
	for (int n = 1; n <= 10; n++)
	{
		if (n <= percentage)
			cout << "|";
		else
			cout << ".";
	}
	cout << "]>" << endl;
	cout << "HP: \t" << _chp << "/" << _hp << "\tArmor:\t" << _carmor << endl;
	cout << "Atk: \t" << _atk << "\tRange:\t" << _catkRange << endl;
	cout << "Position: \t(" << getPosition("x") << "," << getPosition("y") << ")\tRecovering: " << _recoveringFor;
	cout << "\n--------------------------------------------------------- \n";
}

//getters 
int Unit::getHP()
{
	return _hp;
}
int Unit::getCHP()
{
	return _chp;
}
int Unit::getArmor()
{
	return _armor;
}
int Unit::getCArmor()
{
	return _carmor;
}
int Unit::getCAtkRange()
{
	return _catkRange;
}
int Unit::getPosition(string xy)
{
	
	if (xy == "x")
	{
		return _posX;
	}
	else if (xy == "y")
	{
		return _posY;
	}
	else return -1;
}

//setters
void Unit::setCHP(int chp)
{
	_chp = chp;
}
void Unit::setCArmor(int carmor)
{
	_carmor = carmor;
}
void Unit::setName(string name)
{
	_name = name;
}
void Unit::setPosition(int x, int y)
{
	//if(x!=NULL)
		_posX = x;
	//if(y!=NULL)
		_posY = y;
	
}
//misc
string Unit::toString()
{
	return "_";
}
bool Unit::isAssigned()
{
	if (_class != "Unassigned")
		return true;
	else
		return false;
}
void target(Board b)
{
	cout << "This unit can't attack.\n";
}