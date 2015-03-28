#include <iostream>
#include "Board.hpp"
#include "Edge.hpp"
#include "Unit.hpp"
#include "Knight.hpp"
#include "Marksman.hpp"
#include "Priest.hpp"
#include "Frostbinder.hpp"
#include "Assassin.hpp"
#include "Hag.hpp"
 
#include <string>
#include <vector>

using namespace std;
Board::Board(){
	//fill board with empty spaces
	for (int i = 0; i < _dimensions; i++)
	{
		for (int j = 0; j < _dimensions; j++)
		{
			Unit * temp = new Unit;
			_array[i][j] = temp;
			_array[i][j]->setPosition(i, j);
		}
	}
	//populate corners with Edge units
	populateEdges();
	buildaBoard();

	//start turn system
	startTurns();
}
//draw, turn and pull
bool Board::commandIn()
{
	string input = "", prefix = "";
	//Unit * focus, target;
	cout << ">Please enter a command: ";
	cin >> input;
	if (input == "exit")
	{
		cout << ">EXIT: Exiting. Byee!\n";
		_endofgame = true;
		return false;
	}
	else if (input == "endturn")
	{
		cout << ">TURN: Ending turn.\n";
		return false;
	}
	else
	{
		if (input == "attack")
		{
			cout << ">ATTACK: Select Attacker.\n";
			int x = grabXCoord(), y = grabYCoord();
			Unit * focus = fetchUnitAt(x,y);
			if (focus->_recoveringFor == 0)
			{
				if (focus->isAssigned())
				{
					if (focus->_singleTarget == false)
					{
						cout << focus->_name << " the " << focus->_class << " will target the board. Continue Y/N? ";
						string response = "";
						cin >> response;
						if (response == "y" || response == "Y")
							focus->target(this);
					}
					else
					{
						cout << ">ATTACK: Select Target.\n";
						int x2 = grabXCoord(), y2 = grabYCoord();
						Unit * target = fetchUnitAt(x2, y2);
						focus->attack(target);
						cout << ">ATTACK: Complete.\n";
					}
				}

				else
					cout << ">ATTACK: Invalid target. Restarting loop.\n";
			}
			else
			{
				cout << ">ATTACK: Unit is still recovering. Restarting loop.\n";
			}
			return true;
		}
		else if (input == "move")
		{
			cout << ">MOVE: Select a unit to move.\n";
			int x = grabXCoord(), y = grabYCoord();
			Unit *focus = fetchUnitAt(x,y);
			if (focus->_class != "Unassigned")
			{
				cout << ">MOVE: Select a target point.\n";
				int x2 = grabXCoord(), y2 = grabYCoord();
				//Unit * target = fetchUnitAt(coords[0], coords[1]);
				//if (!target->isAssigned())
				moveUnit(focus, x2, y2);
				//else
				//	cout << ">MOVE: Target position is occupied. Restarting loop.\n";
				return true;
			}
			else
				cout << ">MOVE: Coordinates are empty. Restarting loop.\n";
		}
		else if (input == "board")
			return true;
		else if (input == "range")
		{
			cout << ">RANGE: Which unit?\n";
			int x = grabXCoord(), y = grabYCoord();
			Unit *focus = fetchUnitAt(x, y);
			cout << ">RANGE: Attack or movement range? ";
			string response = "";
			cin >> response;
			if (response == "attack")
			{
				drawRange(focus, "atk");
			}
			else
				drawRange(focus,"mov");
		}
		else if (input == "info")
		{
			cout << ">INFO: Select a unit to display.\n";
			int x = grabXCoord(), y = grabYCoord();
			Unit *focus = fetchUnitAt(x, y);
			if (focus->_class != "Unassigned");
				focus->printAll();
		}
		else if (input == "help")
		{
			cout << ">HELP:-----------------------------------------\n"
				<< "Command: \tAction:\n"
				<< "-\t\t-\n"
				<< "exit \t\tEnd the game.\n"
				<< "endturn \tWrap up and pass the turn to the next player.\n"
				<< "attack \t\tStart an attack sequence.\n"
				<< "move \t\tStart a move sequence.\n"
				<< "board\t\tPrint a picture of the board.\n"
				<< "range\t\tChoose a unit to see their movement or attack range.\n"
				<< "info\t\tPrint a bunch of helpful info about a unit.\n"
				<< "help\t\tDisplay a bunch of helpful commands.\n"
				<< "-----------------------------------------------\n";
		}
		else
			cout << ">Unknown input. Try again.\n";
		return true;
	}
}
void Board::toString()
{
	string str = "";
	cout << "_________________________\n";
	cout << "   0|1|2|3|4|5|6|7|8|9|0|\n";
	for (int i = 0; i < _dimensions; i++)
	{
		if (i != 10)
			cout << " ";
		cout << i << "|";
		for (int j = 0; j < _dimensions; j++)
		{
			str = this->_array[i][j]->toString();
			cout << str << "|";
		}
		cout << endl;
	}
	cout << "_______________________\n";
}
void Board::drawRange(Unit * unit, string str = "atk")
{

	int k = _dimensions;
	cout << "_______________________\n";
	for (int i = 0; i < k; i++)
	{
		cout << "|";
		for (int j = 0; j < k; j++)
		{
			Unit * temp = _array[i][j];
			if (temp->_class != "Unassigned")
			{
				cout << temp->toString();
			}
			else
			{
				int ax, ay, ar;
				ax = unit->getPosition("x");
				ay = unit->getPosition("y");
				if (str == "atk")
					ar = unit->_catkRange;
				else
					ar = unit->_movementRange;
				if ((abs(ax - i) + abs(ay - j)) <= ar)
				{
					cout << "+";
				}
				//if (unit->canMove(j,i))
				//	cout << "+";

				else
					cout << "_";
			}
			cout << "|";
		}
		cout << endl;
	}
	cout << "_______________________\n";
}

//find and manipulate
Unit * Board::fetchUnitAt(int x, int y)
{	
	Unit * selected = _array[x][y];
	cout << "Selected " << selected->_name << " the " << selected->_class << " from team " << selected->_team << ".\n";
	return selected;
}
void Board::moveUnit(Unit * unit, int x, int y)
{
	int tx = unit->getPosition("x");
	int ty = unit->getPosition("y");
	cout << "Moving unit at " << tx << "," << ty << " to " << x << "," << y << endl;
	if (x < _dimensions && y < _dimensions && unit->_isParalyzed == false)
	{
		_array[x][y] = unit;
		unit->setPosition(x, y);
		_array[tx][ty] = new Unit();
		if (unit->_isFocused)
		{
			unit->_isFocused = false;
			unit->_focusedOn->_isParalyzed = false;
		}
		//unit->_recoveringFor += 1;
	}
	else cout << "Can't move unit to " << x << "," << y << "\n";
}
void Board::place(Unit * unit, int x, int y)
{
	int xold = unit->getPosition("x");
	//cout << xold << endl;
	int yold = unit->getPosition("y");
	//cout << yold << endl;

	_array[x][y] = unit;
	unit->setPosition(x, y);
	//place(new Unit(), xold, yold);
}
int Board::grabXCoord()
{
	int x = 0;
	cout << ">X Coordinate: ";
	cin >> x;
	return x;
}
int Board::grabYCoord()
{
	int y = 0;
	cout << ">Y Coordinate: ";
	cin >> y;
	
	return y;
	
}

//turn system
void Board::startTurns()
{
	cout << ">TURN: Starting turn system.\n>TURN: Flipping coin...\n>TURN: Rolled a ";
	srand(time(NULL)); 
	int rng = rand() % 100 + 1;
	if (rng <= 50)
	{
		cout << "Heads!\n";
		_team = 0;
	}
	else
	{
		cout << "Tails!\n";
		_team = 1;
	}
	turn();
	//end game once someone loses

	if (_team == 0)
		cout << "Team 0 has won!!\n";
	else if (_team == 1)
		cout << "Team 1 has won!!\n";
	else
		cout << "You tied somehow. grats.\n";
}
void Board::turn()
{
	//state whose turn it is
	cout << ">TURN: Team " << _team << "'s turn to move.\n";

	//apply start-of-turn effects (poison,
	playStartEffects();
	killDead();
	//start taking commands
	bool loop = true;
	while (loop)
	{
		toString();
		loop = commandIn();
	}
	//break loop on 'exit'

	//apply end-of-turn effects
	playEndEffects();
	recover();

	//check if anything is dead
	killDead();

	//if game isn't over restart loop
	if (!gameOver() && !_endofgame)
	{
		_team = abs(_team - 1);
		turn();
	}
}
void Board::playStartEffects()
{}
void Board::playEndEffects()
{}
void Board::killDead()
{
	//iterate through board and replace any dead units with empty units
	for (int i = 0; i < _dimensions; i++)
	{
		for (int j = 0; j < _dimensions; j++)
		{
			if (_array[i][j]->_chp <= 0)
			{
				cout << _array[i][j]->_name << " the " << _array[i][j]->_class << " has died.\n";
				_array[i][j] = new Unit();
			}
		}
	}
}
bool Board::gameOver()
{
	int count0 = 0, count1 = 0;
	for (int i = 0; i < _dimensions; i++)
	{
		for (int j = 0; j < _dimensions; j++)
		{
			if (_array[i][j]->_team==0)
			{
				count0++;
			}
			else if (_array[i][j]->_team == 1)
			{
				count1++;
			}
		
		}
	}
	//count dead
	if (count0 <= 0 && count1>0)
	{
		_team = 1;
		return true;
	}
	else if (count1 <= 0 && count0 > 0)
	{
		_team = 0;
		return true;
	}
	else
		return false;
}
void Board::recover()
{
	for (int i = 0; i < _dimensions; i++)
	{
		for (int j = 0; j < _dimensions; j++)
		{
			Unit * temp = _array[i][j];
			if (temp->_team == _team && temp->_recoveringFor >=0)
			{
				temp->_recoveringFor -= 1;
			}
		}
	}
}
//build and populate
void Board::populateEdges()
{
	Unit * e = new Edge();

	//top left
	place(e, 0, 0);
	place(e, 0, 1);
	place(e, 1, 0);

	//top right
	place(e, 0, _dimensions - 1);
	place(e, 0, _dimensions - 2);
	place(e, 1, _dimensions - 1);

	//bottom left
	place(e, _dimensions - 1, _dimensions - 1);
	place(e, _dimensions - 1, _dimensions - 2);
	place(e, _dimensions - 2, _dimensions - 1);

	//bottom right
	place(e, _dimensions - 1, 0);
	place(e, (_dimensions - 2), 0);
	place(e, _dimensions - 1, 1);
}
void Board::populateFromArray(Unit * units[10], int x[10], int y[10])
{
	for (int i = 0; i < 10; i++)
	{
		place(units[i], x[i], y[i]);
	}
}
void Board::buildaBoard()
{
	cout << "Pulling board information from files...\n";
	Unit * units1[10];
	Unit * units0[10];
	int x0[10];
	int x1[10];
	int y0[10];
	int y1[10];

	units1[0] = new Knight(1, "Oscar");
	units1[1] = new Knight(1, "Mayer");
	units1[2] = new Knight(1, "Name");
	units1[3] = new Priest(1, "Bitch");
	units1[4] = new Assassin(1, "Stabby");
	units1[5] = new Marksman(1, "Wilde");
	units1[6] = new Marksman(1, "Shooter");
	units1[7] = new Hag(1, "Creepy");
	units1[8] = new Frostbinder(1, "Frosty");
	units1[9] = new Frostbinder(1, "Frosty Jr");

	x1[0] = 4; //knight 1
	x1[1] = 5; //knight 2
	x1[2] = 6; //knight 3
	x1[3] = 5; //Priest 1
	x1[4] = 1; //Assassin 1
	x1[5] = 2; //mm 1
	x1[6] = 9; //mm 2
	x1[7] = 8; //hag 1
	x1[8] = 5; //frosty 1
	x1[9] = 5;//frosty 2

	y1[0] = 3;
	y1[1] = 3;
	y1[2] = 3;
	y1[3] = 0;
	y1[4] = 2;
	y1[5] = 2;
	y1[6] = 2;
	y1[7] = 2;
	y1[8] = 1;
	y1[9] = 2;

	units0[0] = new Knight(0, "Oscar");
	units0[1] = new Knight(0, "Mayer");
	units0[2] = new Knight(0, "Name");
	units0[3] = new Priest(0, "Bitch");
	units0[4] = new Assassin(0, "Evil Stabby");
	units0[5] = new Marksman(0, "Wilde");
	units0[6] = new Marksman(0, "Shooter");
	units0[7] = new Hag(0, "Creepy 2");
	units0[8] = new Frostbinder(0, "Frosty");
	units0[9] = new Frostbinder(0, "Frosty Jr");

	x0[0] = 4; // knight 1
	x0[1] = 5; // knight 2
	x0[2] = 6; // knight 3
	x0[3] = 5; // Priest 1
	x0[4] = 9; // Assassin 1
	x0[5] = 1; // mm 1
	x0[6] = 2; // mm 2
	x0[7] = 8; // hag 1
	x0[8] = 5; // frosty 1
	x0[9] = 10;// frosty 2

	y0[0] = 8;
	y0[1] = 8;
	y0[2] = 8;
	y0[3] = 10;
	y0[4] = 8;
	y0[5] = 8;
	y0[6] = 8;
	y0[7] = 8;
	y0[8] = 9;
	y0[9] = 10;

	populateFromArray(units0, x0, y0);
	populateFromArray(units1, x1, y1);
	cout << "Board imported. Have fun!\n";
}