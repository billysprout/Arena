#ifndef _UNIT_HPP_
#define _UNIT_HPP_
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <array>

#include "board.hpp"

#pragma warning(disable: 4244)

using namespace std;
class Board;
class Unit {
public:
	//member variables

	//class-specific stats
	int _hp, _armor, _atkRange, _atkType, _atk, _recovery, _blkChance, _movementRange;

	//game-context stats
	int _chp, _carmor, _catkRange, _team, _recoveringFor;

	//position on the board
	int _posX, _posY;

	//status effects
	bool _isParalyzed, _isProtected, _isArtifact, _isFocused, _singleTarget;
	
	string _name = "Default", _class = "Unassigned";

	Unit * _focusedOn;
	Unit * _focusedBy;

	//virtual functions
	Unit();
	virtual void damage(Unit * attacker);
	virtual bool block(int side);
	virtual bool block(int side, int atkType);
	virtual void printAll();
	virtual int getHP();
	virtual int getCHP();
	virtual int getArmor();
	virtual int getCArmor();
	virtual void setCHP(int chp);
	virtual void setCArmor(int carmor);
	virtual void setName(string name);
	virtual string toString();
	virtual int getPosition(string xy);
	virtual void setPosition(int x, int y);
	virtual void attack(Unit * target);
	virtual void attack(Board b);
	virtual bool canAttack(Unit * target);
	virtual int getCAtkRange();
	virtual bool canMove(int x, int y);
	virtual bool isAssigned();

	virtual void target(Board *b);
};

#endif //_UNIT_HPP_