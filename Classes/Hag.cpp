#include "Hag.hpp"

Hag::Hag(int team, string name = "Hag")
{
		_hp = 28, _armor = 0, _atkRange = 4, _atkType = 1, _atk = 24, _recovery = 2, _blkChance = 0;
		_chp = _hp, _carmor = _armor, _catkRange = _atkRange;
		_name = name;
		_class = "Hag";
		_posX = 0;
		_posY = 0;
		_team = team;
		_movementRange = 3;
		_singleTarget = false;
}
string Hag::toString()
{
	return "†";
}
void Hag::target(Board *b)
{
	string response = "";
	if (_recoveringFor == 0)
	{
		while (response != "north" && response != "south" && response != "east" && response != "west")
		{
			cout << ">ATTACK: Target north, east, south or west: ";
			cin >> response;
		}
		if (response == "east")
		{
			int x = getPosition("x");
			int y = getPosition("y");
			if ((y + 1) < b->_dimensions)
			{
				if (b->_array[x][y + 1]->_class != "Unassigned")
				this->attack(b->_array[x][y + 1]);
				if ((y + 2) < b->_dimensions)
				{
					if (b->_array[x][y + 2]->_class != "Unassigned")
					this->attack(b->_array[x][y + 2]);
					if ((y + 3) < b->_dimensions)
					{
						if (b->_array[x][y + 3]->_class != "Unassigned")
						this->attack(b->_array[x][y + 3]);
						if ((y + 4) < b->_dimensions)
						{
							if (b->_array[x][y + 4]->_class != "Unassigned")
							this->attack(b->_array[x][y + 4]);
						}
					}
				}
			}
			else
				cout << ">ATTACK: You attacked a wall.\n";
		}
		if (response == "west")
		{
			int x = getPosition("x");
			int y = getPosition("y");
			if ((y - 1) < b->_dimensions)
			{
				if (b->_array[x][y - 1]->_class != "Unassigned")
				this->attack(b->_array[x][y - 1]);
				if ((y - 2) < b->_dimensions)
				{
					if (b->_array[x][y - 2]->_class != "Unassigned")
					this->attack(b->_array[x][y - 2]);
					if ((y - 3) < b->_dimensions)
					{
						if (b->_array[x][y - 3]->_class != "Unassigned")
						this->attack(b->_array[x][y - 3]);
						if ((y - 4) < b->_dimensions)
						{
							if (b->_array[x][y -4]->_class != "Unassigned")
							this->attack(b->_array[x][y - 4]);
						}
					}
				}
			}
			else
				cout << ">ATTACK: You attacked a wall.\n";
		}
		if (response == "south")
		{
			int x = getPosition("x");
			int y = getPosition("y");
			if ((x + 1) < b->_dimensions)
			{
				if (b->_array[x + 1][y]->_class != "Unassigned")
				this->attack(b->_array[x + 1][y]);
				if ((x + 2) < b->_dimensions)
				{
					if (b->_array[x + 2][y]->_class != "Unassigned")
					this->attack(b->_array[x + 2][y]);
					if ((x + 3) < b->_dimensions)
					{
						if (b->_array[x + 3][y]->_class != "Unassigned")
						this->attack(b->_array[x + 3][y]);
						if ((x + 4) < b->_dimensions)
						{
							if (b->_array[x + 4][y]->_class != "Unassigned")
							this->attack(b->_array[x + 4][y]);
						}
					}
				}
			}
			else
				cout << ">ATTACK: You attacked a wall.\n";
		}
		if (response == "north")
		{
			int x = getPosition("x");
			int y = getPosition("y");
			if ((x - 1) < b->_dimensions)
			{
				if (b->_array[x - 1][y]->_class != "Unassigned")
				this->attack(b->_array[x - 1][y]);
				if ((x - 2) < b->_dimensions)
				{
					if (b->_array[x - 2][y]->_class != "Unassigned")
					this->attack(b->_array[x - 2][y]);
					if ((x - 3) < b->_dimensions)
					{
						if (b->_array[x - 3][y]->_class != "Unassigned")
						this->attack(b->_array[x - 3][y]);
						if ((x - 4) < b->_dimensions)
						{
							if (b->_array[x - 4][y]->_class != "Unassigned")
							this->attack(b->_array[x - 4][y]);
						}
					}
				}
			}
			else
				cout << ">ATTACK: You attacked a wall.\n";
		}
		_recoveringFor += 2;
	}
}