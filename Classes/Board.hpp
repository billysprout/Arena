#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include <iostream>
#include "Unit.hpp"
#include <string>
#include <array>
#include <vector>

//forward declaration!!!
class Unit;

using namespace std;
class Board{
public:
	int _dimensions = 11, _team=-1;
	bool _endofgame = false;
	//vector <vector<Unit*>> _array(Unit*, vector<Unit*>(_dimensions));
	Unit* _array[11][11];
	Board();
	//draw and pull
	virtual bool commandIn();
	virtual void toString();
	virtual void drawRange(Unit* unit, string str);

	//find and manipulate
	virtual Unit* fetchUnitAt(int x, int y);
	virtual void moveUnit(Unit * Unit, int x, int y);
	virtual void place(Unit* unit, int x, int y);
	virtual int grabXCoord();
	virtual int grabYCoord();

	//turn system
	virtual void startTurns();
	virtual void turn();
	virtual void playStartEffects();
	virtual void playEndEffects();
	virtual void killDead();
	virtual bool gameOver();
	virtual void recover();

	//build and populate
	virtual void populateEdges();
	virtual void populateFromArray(Unit* units[10],int x[10],int y[10]);
	virtual void buildaBoard();
};
#endif //_BOARD_HPP_